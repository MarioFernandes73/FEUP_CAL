/*
 * Edge.cpp
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#include "Edge.h"

template <class T>
Edge<T>::Edge(Vertex<T> * d, double w){
	this->dest = d;
	this->weight = w;
}
