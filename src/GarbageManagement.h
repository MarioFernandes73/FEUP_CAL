/*
 * GarbageManagement.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef GARBAGEMANAGEMENT_H_
#define GARBAGEMANAGEMENT_H_



#include <vector>

#include "Vehicle.h"
#include "graphviewer.h"
#include "Graph.h"
#include "Location.h"
#include "Garage.h"
#include "Station.h"
#include "Container.h"


class GarbageManagement {
private:
	Graph<Location> graph;
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle *> vehicles;

	std::vector <Garage *> garages;
	std::vector <Container *> containers;
	std::vector <Station *> stations;

public:
	GarbageManagement();
	void addStation(Station * station);
	void addContainer(Container * container);
	void addGarage(Garage * garage);
	Location * getLocation(int id);
	Station * getStation(int id);
	Container * getContainer(int id);
	Garage * getGarage(int id);

	void addEdge(double weight, pair<int,int> vertexesCoord);

	void addVehicle(Vehicle * vehicle, int id);

	void calculateShortestPath(int id);

	virtual ~GarbageManagement();
};

#endif /* GARBAGEMANAGEMENT_H_ */
