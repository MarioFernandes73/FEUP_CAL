/*
 * Vertex.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;

template <class T>
class Vertex {
private:
	T info;
	std::vector<Edge<T>> adj;
	bool visited;
public:
	Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> * dest, double w);
	bool removeEdgeTo(Vertex<T> * d);
};

#endif /* VERTEX_H_ */
