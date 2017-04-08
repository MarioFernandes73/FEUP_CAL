/*
 * GarbageManagement.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef GARBAGEMANAGEMENT_H_
#define GARBAGEMANAGEMENT_H_



#include <vector>
#include <map>

#include "Vehicle.h"
#include "graphviewer.h"
#include "Graph.h"
#include "Location.h"
#include "Garage.h"
#include "Station.h"
#include "Container.h"


class GarbageManagement {
private:
	static long edgeCounter;
	Graph<Location> graph;
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle *> vehicles;

	std::vector <Location *> genericLocations;
	std::vector <Garage *> garages;
	std::vector <Container *> containers;
	std::vector <Station *> stations;
	std::map<std::pair<long,long>,long> edges;

public:
	GarbageManagement();
	void addLocation(Location * location);
	void addStation(Station * station);
	void addContainer(Container * container);
	void addGarage(Garage * garage);
	void addEdge(double weight, pair<long,long> vertexesCoord);
	void addVehicle(int id, Vehicle * vehicle);

	Location * getGenericLocation(long id);
	Location * getLocation(long id);
	Station * getStation(long id);
	Container * getContainer(std::pair<double,double> coord);
	Container * getContainer(long id);
	Garage * getGarage(long id);
	vector<Garage *> getValidGarages(Container * container);
	Graph<Location> getGraph();

	void removeLocation(long id);
	void removeStation(long id);
	void removeContainer(long id);
	void removeGarage(long id);
	void removeEdge(pair<long,long> vertexesCoord);
	void removeVehicle(string plate);

	void setGarage(long id);
	void setContainer(long id, garbageType type, double quantity);
	void setStation(long id);

	void fillContainer(long id);
	void clearContainer(long id);

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
