#include <iostream>
#include <vector>
#include <iterator> 
#include <map> 
#include <string>
#include <bits/stdc++.h>
#include <functional>
#include <utility>
#include <queue>
#include <fstream>

using namespace std;

map<vector<vector<int> > , bool> visited; //mapa "visited" que pega vetor(que guarda vetores do tipo int) como chaves,a boolean como valor
map<vector<vector<int> > , vector<vector<int> > > parent; //mapa "parent" que pega vetoes como chave e valor para manter controle dos nós
vector<vector<int> > goal(3,vector<int> (3)); 

bool visit(vector<vector<int> > a)  //boolean para ver se o nó foi visitado
{
	if(visited[a]==true)
		return true;
	
	return false;
}


//Manhattan para achar a distancia
int manhattan (vector<vector<int> > a , int moves)
{
	int dist = moves;
	for (int i=0; i<3; i++) //loop para passar em cada linha e coluna
	{
		for (int j=0; j<3; j++)
		{
			if(a[i][j] != 0)
			{
				for (int k=0; k<3; k++)
				{
					for (int l=0; l<3; l++)
					{
						if(a[i][j]==goal[k][l])
							dist+=abs(i-k)+abs(j-l); //valor absoluto pois pode ser negativo
					}
				}
			}
		}
	}
	return dist;	
}

bool isGoal (vector<vector<int> > a){  //boolean para verificar se chegou no goal
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(a[i][j] != goal[i][j]) return 0; //checa se os quadrados  estao na mesma posicao da goal
			
		}
	}
	
	return 1;	
}

bool safe(int i,int j) //boolean para ver se a grid é 3x3
{
	if(i>=0 && i<=2 && j>=0 && j<=2)
		return true;
	
	return false;
}

int dx[]={-1,1,0,0}; //array "dx", com tamanho 4
int dy[]={0,0,1,-1};

vector<vector<vector<int> > > neighbours(vector<vector<int> > a) 
{
	pair<int,int> pos; //vetor de pares "pos" (emparelha um inteiro com outro inteiro)
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++){
			if(a[i][j] == 0) 
			{
				pos.first=i;
				pos.second=j;
				break;
			 } 												
		}		
		
	}
	
	vector<vector<vector<int> > > ans; //vetor "answer" que add os valores corretos dando push back
	for (int k=0; k<4; k++) // 4, nao 3, pois os vetores dx e dy tem tamanho 4
	{
		int cx = pos.first; //para manter o controle dos valores "i"
		int cy = pos.second; //para manter o controle dos valores "j"
		vector<vector<int> > n = a;
		if(safe(cx+dx[k], cy+dy[k]))
		{
			swap(n[cx+dx[k]][cy+dy[k]], n[cx][cy]); //troca posição dos quadrados(arrays)
			ans.push_back(n);			
		}
	}
		
	return ans; //vetor resultado
		
}

typedef pair<vector<vector<int> > , int> state; // define novo tipo "state" que é um vetor de pares
	
struct cmp 
{
	bool operator() (state &a, state &b) // sobrecarregando o operador unário "()"
	{
		int am = manhattan(a.first,a.second);
		int bm = manhattan(b.first,b.second);
		return am<bm;		
	}	
};

void print_path(vector<vector<int> > s)
{
	if(parent.count(s)) //checa se o vetor s esta presente no mapa "parent" que recebe vetores com chave e valores, se estiver presente
	print_path(parent[s]); //imprime o caminho
	
    for(int i=0;i<3;i++)
    {
 	  for(int j=0;j<3;j++)
	  {
		 printf("%d ",s[i][j]);
	  }
	 cout<<endl;
    }
   cout<<endl;
   
 return;
}

void print(vector<vector<int> > s)
{
	for(int i=0;i<3;i++)
   {
	 for(int j=0;j<3;j++)
	 {
		printf("%d ",s[i][j]);
	 }
	cout<<endl;
   }
}


void solve(vector<vector<int> > a, int moves)
{
	
	priority_queue<state, vector<state>, cmp> Q; //Fila de prioridade "Q". 
	Q.push(state(a,moves));
	while(!Q.empty())
	{
		vector<vector<int> > s = Q.top().first;
		Q.pop();
		visited[s]=true;
		if(s==goal) //print(s)
		{
			print_path(s);
			break;
		}
		vector<vector<vector<int> > > ns = neighbours(s);
		vector<vector<vector<int> > >::iterator it;
		for(it=ns.begin();it!=ns.end();it++)
		{
			vector<vector<int> > temp = *it;
			if(!visit(temp))
			{
				parent.insert(pair<vector<vector<int> > , vector<vector<int> > >(temp,s));
				Q.push(state(temp,moves+1));
			}
		}
	}
	return;
}

bool solvable(vector<vector<int> > a, vector<int> v)
{
	//se N for impar e inversao for impar, nao pode resolver, senao pode
	int inv = 0;
	for(int i=0;i<v.size();i++)
	{
		if (v[i] != 0) {
			for(int j=i;j<v.size();j++)
			{
				if (v[i] > v[j] && v[j] != 0){
					inv += 1;
				}
			}
		}
	}
	cout<<"\ninversoes: "<<inv;
	if (inv % 2 == 0) {
		cout<<"\nPuzzle com solucao, aguarde...\n";
		solve(a,0);
	} else {
		cout<<"\nPuzzle sem solucao\n";
		return false;
	}
}

int main()
{
	//1 2 3 4 5 6 8 7 0 (unsolvable)
	//1 3 2 5 0 6 7 8 4 (unsolvable)
	//0 1 3 4 2 5 7 8 6 (solvable)
	cout<<"Digite o puzzle do 8 como string! \n";
	cout<<"\nPor exemplo => 0 1 3 4 2 5 7 8 6\n";
	vector<vector<int> > a(3,vector<int> (3));
	vector<int> v(9);
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			//recebe dados digitados
			cin>>a[i][j];
		}
	}

	for (int i=0; i<3; ++i)
	{
	  for (int j=0; j<3; ++j)
	  {
	     v[i*3 + j] = a[i][j];
	  }
	}
	
	goal[0][0] = 1;
	goal[0][1] = 2;
	goal[0][2] = 3;
	goal[1][0] = 4;
	goal[1][1] = 5;
	goal[1][2] = 6;
	goal[2][0] = 7;
	goal[2][1] = 8;
	goal[2][2] = 0;
	solvable(a, v);
}

