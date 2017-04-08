/*
 * Interaction.h
 *
 *  Created on: 26 Mar 2017
 *      Author: M�rio
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
Location * createNewLocation();
Garage * createGarage();
Container * createContainer();
Station * createStation();

long getLocationID();
long getStationID();
long getSourceLocationID();
long getDestLocationID();
std::string getPlate();

garbageType getGarbageType();
double getQuantity();

/*********
 * Edges *
 *********/
pair<long,long> createEdge();
double createEdgeWeight();

/************
 * Vehicles *
 ************/
Vehicle * createVehicle();


int getAlgorithm();

#endif /* INTERACTION_H_ */
