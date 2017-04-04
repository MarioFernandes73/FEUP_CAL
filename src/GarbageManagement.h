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
	static int edgeCounter;
	Graph<Location> graph;
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle *> vehicles;

	std::vector <Location *> genericLocations;
	std::vector <Garage *> garages;
	std::vector <Container *> containers;
	std::vector <Station *> stations;

public:
	GarbageManagement();
	void addLocation(Location * location);
	void addStation(Station * station);
	void addContainer(Container * container);
	void addGarage(Garage * garage);
	Location * getGenericLocation(int id);
	Location * getLocation(int id);
	Station * getStation(int id);
	Container * getContainer(std::pair<double,double> coord);
	Container * getContainer(int id);
	Garage * getGarage(int id);
	vector<Garage *> getValidGarages(Container * container);
	Graph<Location> getGraph();

	void addEdge(double weight, pair<int,int> vertexesID);

	void addVehicle(int id, Vehicle * vehicle);

	void shortestPathSingleContainer(int id);
	vector<Location> calculateBestPath(vector<vector<Location>> paths);
	double calculatePathScore(vector<Location> path);
	vector<Location> calculateClosestStation(Location location);


	void collectGarbage();
	pair<Location,Location>calculateBestVertexes(std::vector<Location> locations);
	double calculateScoreVertexLocations (Location currentLocation, std::vector<Location> locations);
	std::vector<Garage> getPossibleGarages(std::vector<Location> locations);
	void calculateBestStart(std::pair<Location,Location>&startEndVertexes, std::vector<Garage> possibleGarages, Garage &bestGarage);
	bool loadVehicle(Vehicle * vehicle, Location location);
	Location getNextLocation(Vehicle * vehicle, std::vector<Location> locations);
	bool garagesHasPossibleVehicle(Garage garage, Location location);
	Vehicle * getBestVehicle(Garage garage);
	void moveToStation(Vehicle * vehicle, std::vector<Location>&currentPath);
	void resetVehicles();

	void startTests();

	virtual ~GarbageManagement();
};

#endif /* GARBAGEMANAGEMENT_H_ */
