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
#include "Street.h"


class GarbageManagement {
private:
	int algorithm;
	static long edgeCounter;
	Graph<Location> graph;
	std::string name;
	GraphViewer * viewer;
	std::vector <Vehicle *> vehicles;

	std::vector <Location *> genericLocations;
	std::vector <Garage *> garages;
	std::vector <Container *> containers;
	std::vector <Station *> stations;
	std::vector<Street *> streets;
	//std::vector <std::pair<long,std::pair<long,long>>> edges;

public:
	GarbageManagement();
	virtual ~GarbageManagement();
	Graph<Location> getGraph(){return this->graph;}
	std::vector <Location *> getGenericLocations(){return this->genericLocations;}
	std::vector <Garage *> getGarages(){return this->garages;}
	std::vector <Container *> getContainers(){return this->containers;}
	std::vector <Station *> getStations(){return this->stations;}
	std::vector<Street *> getStreets(){return this->streets;}
	//std::vector <std::pair<long,std::pair<long,long>>> getEdges(){return this->edges;}

	void addLocation(Location * location);
	void addStation(Station * station);
	void addContainer(Container * container);
	void addGarage(Garage * garage);
	void addEdge2(double weight, std::pair<long,long> vertexesCoord);
	void addEdge(double weight, std::pair<long,long> vertexesCoord, std::string name);
	void addEdge(double weight, std::pair<long,long> vertexesCoord){this->addEdge(weight, vertexesCoord, "");}
	void addVehicle(int id, Vehicle * vehicle);
	void addVehicleType(garbageType type, std::string plate);
	void removeVehicleType(garbageType type, std::string plate);

	Location * getGenericLocation(long id);
	Location * getLocation(long id);
	Station * getStation(long id);
	Container * getContainer(std::pair<double,double> coord);
	Container * getContainer(long id);
	Garage * getGarage(long id);
	vector<Garage *> getValidGarages(Container * container);

	void removeLocation(long id);
	void removeStation(long id);
	void removeContainer(long id);
	void removeGarage(long id);
	void removeEdge(pair<long,long> vertexesCoord);
	void removeVehicle(string plate);

	void setGarage(long id);
	void setContainer(long id, garbageType type, double quantity);
	void setStation(long id);
	void setExistingEdges(long id);

	void fillContainer(long id);
	void clearContainer(long id);

	vector<vector<Location>> collectGarbage(int algorithm);
	std::pair<Location,Location>calculateBestVertexes(std::vector<Location> locations);
	double calculateScoreVertexLocations (Location currentLocation, std::vector<Location> locations);
	std::vector<Garage> getPossibleGarages(std::vector<Location> locations);
	void calculateBestStart(std::pair<Location,Location>&startEndVertexes, std::vector<Garage> possibleGarages, Garage &bestGarage);
	bool loadVehicle(Vehicle * vehicle, Location location);
	Location getNextLocation(Vehicle * vehicle, std::vector<Location> locations);
	bool garagesHasPossibleVehicle(Garage garage, Location location);
	Vehicle * getBestVehicle(Garage garage, Location location);
	void moveToStation(Vehicle * vehicle, std::vector<Location>&currentPath);
	std::vector<Location> calculateBestPath(std::vector<std::vector<Location>> paths);
	double calculatePathScore(std::vector<Location> path);

	void startTests();
	void resetVehicles();
	void updateGraph(Location * location);
	void simulatePath(vector<vector<Location>> paths);

	void evaluateConnectivity();


	std::string findStreetExact(std::string input);
	std::string findStreetAproximated(std::string input);
	vector<std::string> findAllStreetAproximated(std::string input);

};

#endif /* GARBAGEMANAGEMENT_H_ */
