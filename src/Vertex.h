/*
 * Vertex.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>

template <class T> class Edge;
template <class T> class Graph;

template <class T>
class Vertex {
private:
	T info;
	std::vector<Edge<T>> adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
public:
	Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> * dest, double w);
	bool removeEdgeTo(Vertex<T> * d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;

	bool operator<(const Vertex<T> vertex);

	Vertex* path;
};

template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};

#endif /* VERTEX_H_ */
