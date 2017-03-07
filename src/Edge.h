/*
 * Edge.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef EDGE_H_
#define EDGE_H_

using namespace std;

template <class T> class Vertex;
template <class T> class Graph;

template <class T>
class Edge {
private:
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> * d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

#endif /* EDGE_H_ */
