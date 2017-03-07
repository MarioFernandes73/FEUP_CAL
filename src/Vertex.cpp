/*
 * Vertex.cpp
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#include "Vertex.h"


template <class T>
Vertex<T>::Vertex(T in){
	this->info = in;
	this->visited = false;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest,w);
	adj.push_back(edgeD);
}
