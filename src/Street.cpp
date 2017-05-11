/*
 * Street.cpp
 *
 *  Created on: 2 May 2017
 *      Author: Mario
 */

#include "Street.h"

long Street::idCounterStreet = 0;
using namespace std;

Street::Street(std::string name, Location * vertex1, Location * vertex2) {
this->id = this->idCounterStreet;
this->vertex1 = vertex1;
this->vertex2 = vertex2;
this->name = name;
this->idCounterStreet++;
}

long Street::getId(){
	return this->id;
}

string Street::getName(){
	return this->name;
}

Location * Street::getLocation1(){
	return this->vertex1;
}

Location * Street::getLocation2(){
	return this->vertex2;
}
Street::~Street() {
	// TODO Auto-generated destructor stub
}

