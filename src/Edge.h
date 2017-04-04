/*
 * Edge.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef EDGE_H_
#define EDGE_H_


template <class T> class Vertex;
template <class T> class Graph;

template <class T>
class Edge {
private:
	Vertex<T> * dest;
	Vertex<T> * orig;
	double weight;
	double flow;
public:
	Edge(Vertex<T> *d, double w, double f=0);
	double getFlow() const;
	double getWeight() const;
	Vertex<T> *getDest() const;
	bool operator<(const Edge<T> &other) const;

	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, double f): dest(d), weight(w), flow(f){}

template <class T>
double Edge<T>::getFlow() const {
	return flow;
}

template <class T>
double Edge<T>::getWeight() const {
	return weight;
}

template <class T>
Vertex<T>* Edge<T>::getDest() const {
	return dest;
}

template <class T>
bool Edge<T>::operator<(const Edge<T> &other) const {
	return this->weight < other.weight;
}

template <class T>
struct edge_greater_than {
    bool operator()(Edge<T> a, Edge<T>  b) const {
        return a.getWeight() > b.getWeight();
    }
};



#endif /* EDGE_H_ */
