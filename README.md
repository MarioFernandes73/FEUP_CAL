# FEUP_CAL
Repository for the course "Concepção e Análise de Algoritmos" (EIC0110) of the second semester of the second year of MIEIC in FEUP.

In this repository there are the 2 practical assignments of this course in the lective year of 2016/2017.

The focus of this C++-based course was the following:

  * Further development of C++ knowledge.
  * Analyzation of diverse types of algorithms many of which related to graphs and path-finding.
  * Calculations of shortest paths using different algorithms such as Dijkstra and Floyd-Warshall's.
  * Calculations of minimum spanning tree using different algorithms such as Prim and Kruskal's.
  * Calculations of maximum flow using different algorithms such as Ford-Fulkerson.
  * Analyzation of string matching algorithms including exact and approximated search algorithms.
  
  The aim of the project was to have a program capable of creating simple graphs and to apply certain algorithms to them.
  The theme of the project was a smart garbage collection system in which there would exist multiple starting points and multiple exits aswel as multiple containers which needed to be collected from. With this in mind, the program created lets the user create any type of graph they wish and apply specifications to the nodes created such as making them containers. When a graph is created the user can then use an algorithm (either Dijkstra or Floyd-Warshall's) to try and find a good solution to the problem at hand. The problem consists on getting all containers collected using the shortest path possible and the least ammount of vehicles.
  
  Due to the nature of the problem, the algorithm created is not optimal especially because of the many combinatory aspects of it being these:
  * Multiple starting points.
  * Multiple exits.
  * Multiple paths.
  * Multiple vehicles on different staring points.
  * Each container can be 1 of many different garbage types.
  * Each container has a certain ammount of garbage volume.
  * Each vehicle can hold a certain ammount of garbage volume.
  * Each vehicle can have 1 or many garbage types.
  
  The project was further expanded to include string matching algorithms, which had the objective of finding a street (graph's edge) by its exact or approximated name.
  
  For further explanation on the project, refer to the paper present on this repository.
   
# PORTUGUESE OFFICIAL PROJECT EXPLANATION

Tema 4: Recolha de Lixo Inteligente
Num sistema tradicional de recolha de lixo, um camião de resíduos passa por todos os pontos de recolha espalhados na cidade, recolhendo o conteúdo dos contentores e transportando-o para um aterro sanitário. Sistemas contemporâneos, entretanto, estimulam a reciclagem, espalhando na cidade contentores específicos para o efeito; o conteúdo, neste caso, é levado para uma estação de tratamento de resíduos onde é tratado adequadamente. 
Considere um sistema de coleta inteligente, onde os contentores estão equipados com sensores de volume, que indicam o momento em que o seu conteúdo precisa ser coletado. Desta forma, os camiões não precisam realizar viagens periódicas, mas apenas realizam o itinerário que inclui contentores cheios.
O sistema a ser desenvolvido deverá considerar a monitorização dos contentores, a partir de sensores de volume, e a capacidade dos veículos de recolha, em função do tipo de resíduo (considere recolha seletiva), a fim de determinar o melhor itinerário a executar, desde a garagem dos veículos, passando pelo maior número de pontos de recolha, até à estação de tratamento de resíduos.
Considere o efeito de frotas homogêneas (com um só tipo de veículo de recolha), assim como frotas heterogêneas (com veículos para cada tipo de resíduo). Considere também a possibilidade de haver mais do que uma garagem, e estações de tratamento, espalhadas na rede, e o seu efeito na eficiência dos algoritmos que implementar.
 
Avalie a conectividade do grafo, a fim de evitar que locais de pontos de recolha se encontrem em zonas inacessíveis a partir do ponto onde se encontra as garagens e as estações de tratamento.
 
Considere a possibilidade de utilizar mapas reais, extraídos do OpenStreetMaps (www.openstreetmap.org), localizando, no mapa, os respectivos locais de recolha, das garagens, e das estações de tratamento.

Tema 4: Recolha de Lixo Inteligente
Para a segunda parte deste trabalho, considere que as ruas têm nomes, por exemplo “Rua de Dr Roberto Frias” ou “A1”, e que pertencem a um dado distrito, por exemplo, “Porto”. Considerando que os contentores de lixo estão localizados em esquinas de cruzamentos entre ruas, estenda o trabalho realizado com funcionalidades apropriadas que permitem a consulta da existência ou não de um contentor num determinado cruzamento entre ruas. Implemente esta funcionalidade, considerando tanto pesquisa exata, assim como pesquisa aproximada, das strings identificativas dos nomes das ruas fornecidas. Para pesquisa exata, caso os nomes de rua não existam, deverá retornar mensagem de lugar desconhecido. Para a pesquisa aproximada, deverá retornar os nomes de ruas mais próximos, ordenados por similaridade, onde poderá haver um contentor.
 
Estas novas funcionalidades deverão ser integradas no trabalho já realizado para a primeira parte. Avalie a complexidade (teórica e empiricamente) dos algoritmos implementados em função dos dados de input usados.

Credits:
* [Mário Fernandes](https://github.com/MarioFernandes73)
* [Bruno Miguel](https://github.com/TheBrunoMiguel)
* [Francisco Maria](https://github.com/francismaria)

