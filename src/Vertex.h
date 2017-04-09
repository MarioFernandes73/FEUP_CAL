/*
 * Vertex.h
 *
 *  Created on: 7 Mar 2017
 *      Author: Mário
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>
#include <cstddef>

template <class T> class Edge;
template <class T> class Graph;
using namespace std;
template <class T>
class Vertex {
private:
	T info;	//location
	vector<Edge<T>  > adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
	int set;
public:
	Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> *dest, double w);
	void addEdge(Vertex<T> *dest, double w, double f);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;
	vector<Edge<T> > getAdj() const;
	Vertex<T>* getPath() const;

	bool operator<(const Vertex<T> vertex);
	bool operator==(const Vertex<T> vertex){return this->info == vertex.getInfo();}

	Vertex* path;

	void updateEdgeFlow(unsigned int index, float f);
	bool getVisited(){return this->visited;}
};

template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};


template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it= adj.begin();
	typename vector<Edge<T> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

//atualizado pelo exercício 5
template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}


template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest,w);
	edgeD.orig = this;
	adj.push_back(edgeD);
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w, double f)
{
	Edge<T> edgeD(dest, w, f);
	edgeD.orig = this;
	adj.push_back(edgeD);
}


template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
int Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
vector<Edge<T> > Vertex<T>::getAdj() const {
	return this->adj;
}

template <class T>
Vertex<T>* Vertex<T>::getPath() const {
	return this->path;
}


template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template <class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

template <class T>
void Vertex<T>::updateEdgeFlow(unsigned int index, float f)
{
	if (index >= adj.size())
		return;
	adj[index].flow = f;
}



#endif /* VERTEX_H_ */
