/*
 * Graph.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>

#include "Vertex.h"
#include "Edge.h"

template <class T>
class Graph {
private:
	std::vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, std::vector<T> &res) const;

	//exercicio 5
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, std::list<T> &res);

	//exercicio 6
	int ** W;   //weight
	int ** P;   //path
public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	std::vector<T> dfs() const;
	std::vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	std::vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;

	//exercicio 5
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();							//updates vertex's indegrees
	std::vector<Vertex<T>*> getSources() const;		//returns source vertex's of the graph
	int getNumCycles();
	std::vector<T> topologicalOrder();
	std::vector<T> getPath(const T &origin, const T &dest);
	void unweightedShortestPath(const T &v);
	bool isDAG();									//checks if graph is acyclic

	//exercicio 6
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);
	void floydWarshallShortestPath();
	int edgeCost(int vOrigIndex, int vDestIndex);
	std::vector<T> getfloydWarshallPath(const T &origin, const T &dest);
	void getfloydWarshallPathAux(int index1, int index2, std::vector<T> & res);
};

#endif /* GRAPH_H_ */
