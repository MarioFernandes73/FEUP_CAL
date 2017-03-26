/*
 * Edge.h
 *
 *  Created on: 7 Mar 2017
 *      Author: M�rio
 */

#ifndef EDGE_H_
#define EDGE_H_


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

#include "Edge.h"

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}



#endif /* EDGE_H_ */
