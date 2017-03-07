/*
 * Graph.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

template <class T>
class Graph {
private:
	std::vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, std::vector<T> &res) const;
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
};

#endif /* GRAPH_H_ */
