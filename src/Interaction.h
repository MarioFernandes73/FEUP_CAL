/*
 * Interaction.h
 *
 *  Created on: 26 Mar 2017
 *      Author: Mário
 */

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include "Vertex.h"
#include "Location.h"
#include "Station.h"
#include "Garage.h"
#include "Container.h"


/************
 * Vertexes *
 ************/
void createLocation(string&name, pair<double,double>&coordinates);
Garage * createGarage();
Container * createContainer();
Station * createStation();

int getSourceLocationID();
int getDestLocationID();

garbageType getGarbageType();
double getQuantity();

/*********
 * Edges *
 *********/
pair<int,int> createEdge();
double createEdgeWeight();


/************
 * Vehicles *
 ************/
Vehicle * createVehicle();

#endif /* INTERACTION_H_ */
