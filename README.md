# 8-puzzle
## Greedy Search
É um algoritmo que busca sempre fazer a melhor escolha aparente num determinando momento, ou seja, ele faz a melhor escolha localmente na esperança de chegar na melhor escolha global, mesmo assim, ele não é considerado um algoritmo com uma boa otimização. Outro detalhe, é que esse algoritmo possui apenas uma oportunidade para fazer a escolha ideal, portanto ele nunca retorna e refaz a escolha anterior.
## A*
É um dos algoritmos com maior sucesso para achar o caminho mais curto entre dois pontos, utiliza valores para identificar o caminho de menor valor e heurísticas para chegar na solução. Ele possui otimalidade e completude, ou seja, contanto que exista um solução, ela vai ser achada, assim como é garantido que vai ser a melhor solução.
## Graph Search
Qualquer algoritmo que visita todos os vértices de um grafo, andando pelos arcos de um vértice a outro, pode ser considerado um algoritmo de busca em grafo. Ele possui um nó de inicio e um de chegada. Existem diversos tipos de algoritmos de grafo, mas dois muito utilizados e conhecidos são o algoritmo de busca em profundidade (DFS) e o de busca em amplitude (BFS). O BFS repetidamente escolhe o nó mais próximo inexplorado e o explora, parando somente quando explorar todos os nós ou ter chegado na solução desejada. Enquanto DFS, escolhe o nó mais longe, para daí fazer o caminho de volta ao inicio, repetindo esse procedimento até explorar o grafo por completo ou chegar na solução desejada. Devido ao seu funcionamento, busca em grafo não é considerada otimizada.
## Referências
- https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/
- https://brilliant.org/wiki/greedy-algorithm/
- https://brilliant.org/wiki/a-star-search/
- https://www.geeksforgeeks.org/greedy-algorithms-general-structure-and-applications/
- https://www.geeksforgeeks.org/a-search-algorithm/
- https://towardsdatascience.com/a-star-a-search-algorithm-eb495fb156bb
- https://ai-master.gitbooks.io/classic-search/content/chapter1.html
- http://www.cs.cmu.edu/afs/cs/academic/class/15210-s15/www/lectures/graph-search-notes.pdf
- https://www.gatevidyalay.com/tag/a-algorithm-for-8-puzzle-problem/
- https://blog.goodaudience.com/solving-8-puzzle-using-a-algorithm-7b509c331288
- https://github.com/ani94/8-puzzle-solver-cpp/blob/master/8puzzle.cpp
