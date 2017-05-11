/*
 * GarbageManagement.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "GarbageManagement.h"
#include "edgetype.h"
#include "MyExceptions.h"
#include <sstream>
#include <algorithm>
#include <ctime>

const int typeGarage = 1;
const int typeContainer = 2;
const int typeStation = 3;
int counter = 0;

GarbageManagement::GarbageManagement() {
	this->viewer = new GraphViewer(640,480,false);
	this->viewer->createWindow(640, 480);
	this->viewer->defineVertexColor("blue");
	this->viewer->defineEdgeColor("black");
	this->algorithm = 1;
}

GarbageManagement::~GarbageManagement() {
	// TODO Auto-generated destructor stub
}

void GarbageManagement::addLocation(Location * location)
{
	this->genericLocations.push_back(location);
	this->graph.addVertex((*location));
	this->viewer->addNode(location->getId(),location->getCoordinates().first, location->getCoordinates().second);
	this->viewer->setVertexColor(location->getId(),BLUE);
	this->viewer->rearrange();
}

void GarbageManagement::addGarage(Garage * garage)
{
	this->garages.push_back(garage);
	this->graph.addVertex((*garage));
	this->viewer->addNode(garage->getId(),garage->getCoordinates().first, garage->getCoordinates().second);
	this->viewer->setVertexColor(garage->getId(),YELLOW);
	this->viewer->rearrange();
}

void GarbageManagement::addContainer(Container * container)
{
	this->containers.push_back(container);
	this->graph.addVertex((*container));
	this->viewer->addNode(container->getId(),container->getCoordinates().first, container->getCoordinates().second);
	this->viewer->setVertexColor(container->getId(),BLUE);
	this->viewer->rearrange();
}

void GarbageManagement::addStation(Station * station)
{
	this->stations.push_back(station);
	this->graph.addVertex((*station));
	this->viewer->addNode(station->getId(),station->getCoordinates().first, station->getCoordinates().second);
	this->viewer->setVertexColor(station->getId(),GREEN);
	this->viewer->rearrange();
}

void GarbageManagement::addEdge(double weight, pair<long,long> vertexesCoord, string name)
{
	double trueWeight = weight;
	Location * sourceLocation = getLocation(vertexesCoord.first);
	Location * destLocation = getLocation(vertexesCoord.second);

	if(weight == 0)
	{
		trueWeight = abs(destLocation->getCoordinates().first - sourceLocation->getCoordinates().first)
				+ abs(destLocation->getCoordinates().second - sourceLocation->getCoordinates().second);
	}
	Street * newStreet = new Street(name,sourceLocation, destLocation);
	this->streets.push_back(newStreet);
	this->graph.addEdge((*sourceLocation), (*destLocation), trueWeight);
	this->viewer->addEdge(newStreet->getId(),sourceLocation->getId(), destLocation->getId(),EdgeType().DIRECTED);
	this->viewer->rearrange();
}

void GarbageManagement::addEdge2(double weight, pair<long,long> vertexesCoord)
{
	double trueWeight = weight;
	Location * sourceLocation = getLocation(vertexesCoord.first);
	Location * destLocation = getLocation(vertexesCoord.second);

	if(weight == 0)
	{
		trueWeight = abs(destLocation->getCoordinates().first - sourceLocation->getCoordinates().first)
				+ abs(destLocation->getCoordinates().second - sourceLocation->getCoordinates().second);
	}
	this->graph.addEdge((*sourceLocation), (*destLocation), trueWeight);
	this->viewer->addEdge(Street::getCurrentId(),sourceLocation->getId(), destLocation->getId(),EdgeType().DIRECTED);
	this->viewer->rearrange();
	Street::incCurrentId();
}

void GarbageManagement::addVehicle(int id, Vehicle * vehicle)
{
	Garage * garage = getGarage(id);
	garage->addVehicle(vehicle);
	updateGraph(garage);
}

void GarbageManagement::removeLocation(long id)
{
	Location * location = this->getGenericLocation(id);
	std::vector<Location*>::iterator it;

	for(it = genericLocations.begin(); it != genericLocations.end(); it++){
		if((*it)->getId() == location->getId()){
			genericLocations.erase(it);
			break;
		}
	}
	this->graph.removeVertex((*location));
	this->viewer->removeNode(location->getId());
	this->viewer->rearrange();
}

void GarbageManagement::removeGarage(long id){

	Garage * garage = this->getGarage(id);
	std::vector<Garage*>::iterator it;

	for(it = garages.begin(); it != garages.end(); it++){
		if((*it)->getId() == garage->getId()){
			garages.erase(it);
			break;
		}
	}
	this->graph.removeVertex((*garage));
	this->viewer->removeNode(garage->getId());
	this->viewer->rearrange();
}

void GarbageManagement::removeContainer(long id){

	Container * container = this->getContainer(id);
	std::vector<Container*>::iterator it;

	for(it = containers.begin(); it != containers.end(); it++){
		if((*it) == container){
			containers.erase(it);
			break;
		}
	}
	this->graph.removeVertex((*container));
	this->viewer->removeNode(container->getId());
	this->viewer->rearrange();
}

void GarbageManagement::removeStation(long id){

	Station * station = this->getStation(id);
	std::vector<Station*>::iterator it;

	for(it = stations.begin(); it != stations.end(); it++){
		if((*it) == station){
			stations.erase(it);
			break;
		}
	}
	this->graph.removeVertex((*station));
	this->viewer->removeNode(station->getId());
	this->viewer->rearrange();
}

void GarbageManagement::removeEdge(pair<long,long> vertexesCoord)
{
	long edgeID;
	for(unsigned int i = 0; i< this->getStreets().size(); i++)
	{
		pair<long,long> tempVertexesCoord = pair<long,long>(this->getStreets()[i]->getLocation1()->getId(),this->getStreets()[i]->getLocation2()->getId());
		if( tempVertexesCoord == vertexesCoord){
			edgeID = this->getStreets()[i]->getId();
			this->streets.erase(this->streets.begin()+i);
			break;
		}
	}
	this->graph.removeEdge((*this->getLocation(vertexesCoord.first)),(*this->getLocation(vertexesCoord.second)));
	this->viewer->removeEdge(edgeID);
}

void GarbageManagement::removeVehicle(string plate)
{
	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		for(unsigned int j = 0; j < this->garages[i]->getVehicles().size(); j++)
		{
			if(this->garages[i]->getVehicles()[j]->getPlate() == plate)
			{
				this->garages[i]->getVehicles().erase(this->garages[i]->getVehicles().begin()+j);
				return;
			}
		}
	}

	throw VehicleNotFoundException();
}

Location * GarbageManagement::getLocation(long id)
{
	Location * genericLocation = getGenericLocation(id);
	if(genericLocation != NULL)
		return genericLocation;
	Station * station = getStation(id);
	if(station != NULL)
		return station;
	Garage * garage = getGarage(id);
	if(garage != NULL)
		return garage;
	Container * container = getContainer(id);
	if(container != NULL)
		return container;

	return NULL;
}

Location * GarbageManagement::getGenericLocation(long id)
{
	for(unsigned int i = 0; i < this->genericLocations.size(); i++)
	{
		if(this->genericLocations[i]->getId() == id)
			return genericLocations[i];
	}
	return NULL;
}

Garage * GarbageManagement::getGarage(long id)
{
	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		if(this->garages[i]->getId() == id)
			return garages[i];
	}
	return NULL;
}

Container * GarbageManagement::getContainer(pair<double,double> coord)
{
	for(unsigned int i = 0; i < this->containers.size(); i++)
	{
		if(this->containers[i]->getCoordinates() == coord)
			return containers[i];
	}
	return NULL;
}


Container * GarbageManagement::getContainer(long id)
{
	for(unsigned int i = 0; i < this->containers.size(); i++)
	{
		if(this->containers[i]->getId() == id)
			return containers[i];
	}
	return NULL;
}

Station * GarbageManagement::getStation(long id)
{
	for(unsigned int i = 0; i < this->stations.size(); i++)
	{
		if(this->stations[i]->getId() == id)
			return stations[i];
	}
	return NULL;
}

void GarbageManagement::setExistingEdges(long id)
{
	for(unsigned int i = 0; i < this->getStreets().size(); i++)
	{
		pair<long,long> tempVertexesCoord = pair<long,long>(this->getStreets()[i]->getLocation1()->getId(),this->getStreets()[i]->getLocation2()->getId());
		if(tempVertexesCoord.first == id || tempVertexesCoord.second == id)
		{
			this->addEdge2(0,tempVertexesCoord);
		}
	}
}

void GarbageManagement::setGarage(long id)
{
	Location * location = this->getGenericLocation(id);
	Garage * garage = new Garage(id, location->getCoordinates());
	this->removeLocation(id);
	this->addGarage(garage);
	this->setExistingEdges(id);
}

void GarbageManagement::setContainer(long id, garbageType type, double quantity)
{
	Location * location = this->getGenericLocation(id);
	Container * container = new Container(id, location->getCoordinates(), type, quantity);
	this->removeLocation(id);
	this->addContainer(container);
	this->setExistingEdges(id);
}

void GarbageManagement::setStation(long id)
{
	Location * location = this->getGenericLocation(id);
	Station * station = new Station(id, location->getCoordinates());
	this->removeLocation(id);
	this->addStation(station);
	this->setExistingEdges(id);
}

void GarbageManagement::fillContainer(long id)
{
	Container * container = this->getContainer(id);
	if(container == NULL)
		throw NoValidEntryException();
	container->fillContainer();
	this->viewer->setVertexColor(container->getId(),RED);
	this->viewer->rearrange();
	updateGraph(container);
}

void GarbageManagement::clearContainer(long id)
{
	Container * container = this->getContainer(id);
	container->clearContainer();
	this->viewer->setVertexColor(container->getId(),BLUE);
	this->viewer->rearrange();
	updateGraph(container);
}

void GarbageManagement::addVehicleType(garbageType type, std::string plate)
{
	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		for(unsigned int j = 0; j < this->garages[i]->getVehicles().size(); j++)
		{
			if(this->garages[i]->getVehicles()[j]->getPlate() == plate)
			{
				for(unsigned int k = 0; k < this->garages[i]->getVehicles()[j]->getType().size(); k++)
				{
					if(this->garages[i]->getVehicles()[j]->getType()[k] == type)
					{
						return;
					}
				}
				this->garages[i]->getVehicles()[j]->addType(type);
				return;
			}
		}
	}
	throw VehicleNotFoundException();
}

void  GarbageManagement::removeVehicleType(garbageType type, std::string plate)
{
	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		for(unsigned int j = 0; j < this->garages[i]->getVehicles().size(); j++)
		{
			if(this->garages[i]->getVehicles()[j]->getPlate() == plate)
			{
				this->garages[i]->getVehicles()[j]->removeType(type);
			}
		}
	}
	throw VehicleNotFoundException();
}

void GarbageManagement::updateGraph(Location * location)
{
	for(unsigned int i = 0; i < this->graph.getVertexSet().size(); i++)
	{
		if(this->graph.getVertexSet()[i]->getInfo().getId() == location->getId())
		{
			this->graph.getVertexSet()[i]->setInfo(*location);
		}
	}
}


void GarbageManagement::startTests()
{
	/*
	 * TESTS
	 */

	Garage * l0 = new Garage("ola",pair<double,double>(100,100));
	Garage * l1 = new Garage("ola",pair<double,double>(500,100));
	Location * l2 = new Location("ola",pair<double,double>(250,100));
	Container * l3 = new Container("ola",pair<double,double>(200,200), garbageType::glass,100);
	Container * l4 = new Container("ola",pair<double,double>(400,200), garbageType::glass,100);
	Container * l5 = new Container("ola",pair<double,double>(500,200), garbageType::paper,100);
	Container * l6 = new Container("ola",pair<double,double>(600,200), garbageType::glass,100);
	Container * l7 = new Container("ola",pair<double,double>(700,200), garbageType::glass,100);
	Container * l8 = new Container("ola",pair<double,double>(800,200), garbageType::paper,100);
	Container * l9 = new Container("ola",pair<double,double>(900,200), garbageType::glass,100);
	Container * l10 = new Container("ola",pair<double,double>(1000,200), garbageType::glass,100);
	Container * l11 = new Container("ola",pair<double,double>(1100,200), garbageType::paper,100);
	Station * l12 = new Station("ola",pair<double,double>(100,500));
	Station * l13 = new Station("ola",pair<double,double>(500,500));

	this->addGarage(l0);
	this->addGarage(l1);
	this->addLocation(l2);
	this->addContainer(l3);
	this->addContainer(l4);
	this->addContainer(l5);
	this->addContainer(l6);
	this->addContainer(l7);
	this->addContainer(l8);
	this->addContainer(l9);
	this->addContainer(l10);
	this->addContainer(l11);
	this->addStation(l12);
	this->addStation(l13);

	fillContainer(l3->getId());
	fillContainer(l4->getId());
	fillContainer(l5->getId());
	fillContainer(l6->getId());
	fillContainer(l7->getId());
	fillContainer(l8->getId());
	fillContainer(l9->getId());
	fillContainer(l10->getId());
	fillContainer(l11->getId());

	for(unsigned int i = 0; i<this->garages.size(); i++)
	{
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::glass,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::glass,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::generic,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::paper,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::generic,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::paper,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::plastic,500));
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::plastic,500));
	}

	this->viewer->rearrange();
	this->addEdge(200,pair<int,int>(0,2));
	this->addEdge(100,pair<int,int>(1,2));
	this->addEdge(200,pair<int,int>(2,3));
	this->addEdge(200,pair<int,int>(2,4));
	this->addEdge(100,pair<int,int>(2,5));
	this->addEdge(100,pair<int,int>(3,4));
	this->addEdge(150,pair<int,int>(3,5));
	this->addEdge(100,pair<int,int>(4,3));
	this->addEdge(100,pair<int,int>(4,5));
	this->addEdge(150,pair<int,int>(5,3));
	this->addEdge(100,pair<int,int>(5,4));
	this->addEdge(200,pair<int,int>(3,6));
	this->addEdge(200,pair<int,int>(4,6));
	this->addEdge(200,pair<int,int>(5,6));
	this->addEdge(200,pair<int,int>(3,7));
	this->addEdge(200,pair<int,int>(4,7));
	this->addEdge(200,pair<int,int>(5,7));
	this->addEdge(200,pair<int,int>(5,8));
	this->addEdge(200,pair<int,int>(5,9));
	this->addEdge(200,pair<int,int>(5,10));
	this->addEdge(200,pair<int,int>(5,11));
	this->addEdge(200,pair<int,int>(6,7));
	this->addEdge(200,pair<int,int>(7,5));
	this->addEdge(200,pair<int,int>(8,5));
	this->addEdge(200,pair<int,int>(9,5));
	this->addEdge(200,pair<int,int>(10,5));
	this->addEdge(200,pair<int,int>(11,5));
	this->addEdge(200,pair<int,int>(5,12));
	this->addEdge(200,pair<int,int>(5,13));
}

/*
 * Good solution under these conditions:
 * 1. The containers are much closer to each other than they are to the Garages/Stations
 * this means that minimising the amount of vehicles used will make the overall distance shorter
 * 2. The vehicles have a sufficient capacity to be filled by multiple containers (not fixed capacity
 * but considerably higher than any other container) (this means that in no case it'll be efficient
 * to send out a vehicle to pick up garbage from 1 container and immediately deliver it to a station,
 * unless it's the only left)
 */
vector<vector<Location>> GarbageManagement::collectGarbage(int algorithm)
{
	if(counter == 0 && this->stations.size() == 0 && this->containers.size() == 0 && this->garages.size() == 0)
		startTests();

	if(this->stations.size() == 0 || this->containers.size() == 0 || this->garages.size() == 0)
		throw ImpossibleException();

	this->algorithm = algorithm;
	clock_t begin = clock();
	vector<vector<Location>> paths;

	resetVehicles();


	//run floydWarshallShortestPath to map the distances of the vertexes
	if(algorithm == 1 && counter == 0)
		this->graph.floydWarshallShortestPath();

	//get containers that need to be picked up
	vector<Vertex<Location> *> allVertexes = this->graph.getVertexSet();
	vector<Location> filledContainers;

	for(unsigned int i = 0; i < allVertexes.size(); i++)
	{
		if(allVertexes[i]->getInfo().getLocationType() == typeContainer && allVertexes[i]->getInfo().isFull())
		{
			filledContainers.push_back(allVertexes[i]->getInfo());
		}
	}

	//starting loop
	while(filledContainers.size() != 0)
	{
		// NEW VEHICLE
		vector<Location> currentPath;
		//identify which garages have vehicles that collect the same garbage type as the filledContainers
		vector<Garage> possibleGarages = getPossibleGarages(filledContainers);
		//identify which are the best vertexes to start the collection of garbage
		pair<Location,Location> startEndVertexes;
		//if there is only 1 filled container -> pair <Location,"null" location (has -1 id)>
		if(filledContainers.size() == 1)
		{
			startEndVertexes.first = filledContainers[0];
			startEndVertexes.second = Location(-1,pair<double,double>(0,0));
		}
		else
			startEndVertexes = calculateBestVertexes(filledContainers);
		//identify the best starting vertex
		Garage bestGarage = Garage();
		calculateBestStart(startEndVertexes, possibleGarages, bestGarage);

		currentPath.push_back(bestGarage);
		//we now have the best starting point, the best garage to start in
		Vehicle * currentVehicle = getBestVehicle(bestGarage, startEndVertexes.first);

		if(currentVehicle == NULL)
			break;

		//move to first best vertex
		currentVehicle->moveTo(startEndVertexes.first.getCoordinates().first, startEndVertexes.first.getCoordinates().second);
		currentPath.push_back(startEndVertexes.first);

		if(this->loadVehicle(currentVehicle, startEndVertexes.first))
		{
			for(unsigned int i = 0; i < filledContainers.size(); i++)
			{
				if(filledContainers[i].getId() == startEndVertexes.first.getId())
				{
					filledContainers.erase(filledContainers.begin()+i);
					break;
				}
			}
		}
		while(true)
		{
			// get next best location to go to
			Location nextLocation = this->getNextLocation(currentVehicle, filledContainers);
			if(nextLocation.getId() == -1)
			{
				//vehicle is almost full OR we have no more containers to go to
				this->moveToStation(currentVehicle, currentPath);
				break;
			}

			if(this->loadVehicle(currentVehicle, nextLocation))
			{
				for(unsigned int i = 0; i < filledContainers.size(); i++)
				{
					if(filledContainers[i].getId() == nextLocation.getId())
					{
						currentVehicle->moveTo(filledContainers[i].getCoordinates().first,filledContainers[i].getCoordinates().second);
						currentPath.push_back(filledContainers[i]);
						filledContainers.erase(filledContainers.begin()+i);
						break;
					}
				}
			}
		}
		paths.push_back(currentPath);
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Elapsed time:" << elapsed_secs << endl;

	counter++;
	return paths;
}


void GarbageManagement::resetVehicles()
{
	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		for(unsigned int j = 0; j < this->garages[i]->getVehicles().size(); j++)
		{
			this->garages[i]->getVehicles()[j]->clearVehicle();
		}
	}
}

void GarbageManagement::moveToStation(Vehicle * vehicle, vector<Location>&currentPath)
{
	if(algorithm == 2)
		this->graph.dijkstraShortestPath((*this->getContainer(vehicle->getCurrentCoordinates())));

	Station * bestStation;
	Location vehicleLocation = (*this->getContainer(vehicle->getCurrentCoordinates()));
	double score = INT_MAX;
	for(unsigned int i = 0; i< this->stations.size(); i++)
	{
		double currentScore;
		if(algorithm == 1)
			 currentScore = this->calculatePathScore(this->graph.getfloydWarshallPath((vehicleLocation),(*this->stations[i])));
		else
		{
			currentScore = this->calculatePathScore(this->graph.getPath((vehicleLocation),(*this->stations[i])));
		}

		if(currentScore < score)
		{
			bestStation = this->stations[i];
			score = currentScore;
		}
	}

	vehicle->moveTo(bestStation->getCoordinates().first, bestStation->getCoordinates().second);
	vehicle->fillVehicle();
	currentPath.push_back((*bestStation));
}

Vehicle * GarbageManagement::getBestVehicle(Garage garage, Location location)
{
	Container * container = this->getContainer(location.getId());
	double score = 0;
	Vehicle * bestVehicle = NULL;
	for(unsigned int i = 0; i < garage.getVehicles().size(); i++)
	{
		if(!garage.getVehicles()[i]->isFull())
		{
			bool isAble = false;
			for(unsigned int j = 0; j < garage.getVehicles()[i]->getType().size(); j++)
			{
				if(garage.getVehicles()[i]->getType()[j] == container->getType())
					isAble = true;
			}
			if(!isAble)
				continue;
			else
			{
				double currentScore = garage.getVehicles()[i]->getCapacity() * garage.getVehicles()[i]->getType().size();
				if(currentScore > score)
				{
					bestVehicle = garage.getVehicles()[i];
					score = currentScore;
				}
			}

		}
	}
	return bestVehicle;
}

Location GarbageManagement::getNextLocation(Vehicle * vehicle, vector<Location> locations)
{
	Location bestLocation = Location();
	bestLocation.setID(-1);
	if(locations.size() <= 0)
	{
		return bestLocation;
	}
	//get current location of the vehicle
	Container * currentLocation = this->getContainer(vehicle->getCurrentCoordinates());

	//breadth-first search on locations checking every score
	double minScore = INT_MAX;
	for(unsigned int  i = 0; i< locations.size(); i++)
	{
		if((vehicle->getCapacity() - vehicle->getCurrentCapacity()) > currentLocation->getCapacity())
		{
			bool isAble = false;
			Container * iteratedContainer = this->getContainer(locations[i].getId());
			for(unsigned int j = 0; j < vehicle->getType().size(); j++)
			{
				if(vehicle->getType()[j] == iteratedContainer->getType())
					isAble = true;
			}
			if(!isAble)
				continue;
			else
			{
				double currentScore;
				//score based on weight
				if(algorithm == 1)
					currentScore = this->calculatePathScore(this->graph.getfloydWarshallPath((*currentLocation),locations[i]));
				else
				{
					this->graph.dijkstraShortestPath((*currentLocation));
					currentScore = this->calculatePathScore(this->graph.getPath((*currentLocation),locations[i]));
				}

				if(currentScore < minScore)
				{
					minScore = currentScore;
					bestLocation = locations[i];
				}
			}
		}
	}

	return bestLocation;
}

bool GarbageManagement::loadVehicle(Vehicle * vehicle, Location location)
{
	Container * currentContainer = this->getContainer(location.getId());
	for(unsigned int i = 0; i < vehicle->getType().size(); i++)
	{
		if(currentContainer->getType() == vehicle->getType()[i])
		{
			if(vehicle->loadCurrentCapacity(currentContainer->getCapacity()))
			{
				currentContainer->clearContainer();
				return true;
			}
		}
	}
return false;
}

void GarbageManagement::calculateBestStart(pair<Location,Location>&startEndVertexes, vector<Garage> possibleGarages, Garage &bestGarage)
{
	vector<double> garageVertexesScores1, garageVertexesScores2;
	//paths GARAGES -> VERTEX
	for(unsigned int i = 0; i < possibleGarages.size(); i++)
	{
		if(algorithm == 2)
			this->graph.dijkstraShortestPath(possibleGarages[i]);

		// if the current garage has a vehicle that has the possibility of collecting the garbage on first vertex, iterate through it
		if(garagesHasPossibleVehicle(possibleGarages[i],startEndVertexes.first))
		{
			vector<Location> pathGarageVertex;
			if(algorithm == 1)
			{
				pathGarageVertex = this->graph.getfloydWarshallPath(possibleGarages[i],startEndVertexes.first);
			}
			else
			{
				pathGarageVertex = this->graph.getPath(possibleGarages[i],startEndVertexes.first);
			}
			garageVertexesScores1.push_back(calculatePathScore(pathGarageVertex));

		}
		else	//add placeholder to the vector
		{
			garageVertexesScores1.push_back(INT_MAX);
		}

		if((startEndVertexes.second.getId() != -1) && garagesHasPossibleVehicle(possibleGarages[i],startEndVertexes.second))
		{
			vector<Location> pathGarageVertex;
			if(algorithm == 1)
			{
				pathGarageVertex = this->graph.getfloydWarshallPath(possibleGarages[i],startEndVertexes.second);
			}
			else
			{
				pathGarageVertex = this->graph.getPath(possibleGarages[i],startEndVertexes.second);
			}
			garageVertexesScores2.push_back(calculatePathScore(pathGarageVertex));
		}
		else
		{
			garageVertexesScores2.push_back(INT_MAX);
		}
	}

	double min1 = (*min_element(garageVertexesScores1.begin(), garageVertexesScores1.end()));
	double min2 = (*min_element(garageVertexesScores2.begin(), garageVertexesScores2.end()));

	//we can either choose min1 and min4 OR min2 and min3
	if(min1>min2)
	{
		//starting vertex will be the second of startEndVertexes and garageVertexesScores2[min2] = possibleGarages[bestGarage]
		Location temp = startEndVertexes.first;
		startEndVertexes.first = startEndVertexes.second;
		startEndVertexes.second = temp;

		for(unsigned int i = 0; i<garageVertexesScores2.size(); i++)
		{
			if(garageVertexesScores2[i] == min2)
			{
				bestGarage = possibleGarages[i];
				return;
			}
		}
	}
	else
	{
		//starting vertex will be the first of startEndVertexes and garageVertexesScores1[min1] = possibleGarages[bestGarage]
		for(unsigned int i = 0; i<garageVertexesScores1.size(); i++)
		{
			if(garageVertexesScores1[i] == min1)
			{
				bestGarage = possibleGarages[i];
				return;
			}
		}

	}
}


bool GarbageManagement::garagesHasPossibleVehicle(Garage garage, Location location)
{
	Container currentContainer = (*this->getContainer(location.getCoordinates()));
	for(unsigned int i = 0; i< garage.getVehicles().size(); i++)
	{
		for(unsigned int  k = 0; k<garage.getVehicles()[i]->getType().size(); k++)
		{
			if(!garage.getVehicles()[i]->isFull() && garage.getVehicles()[i]->getType()[k] == currentContainer.getType())
				return true;
		}
	}
	return false;
}

vector<Garage> GarbageManagement::getPossibleGarages(vector<Location> locations)
{
	vector<Garage> possibleGarages;

	for(unsigned int i = 0; i < this->garages.size(); i++)
	{
		bool validGarage = false;
		for(unsigned j = 0; j < this->garages[i]->getVehicles().size(); j++)
		{
			vector<garbageType> currentVehicleTypes = this->garages[i]->getVehicles()[j]->getType();
			for(unsigned int k = 0; k < currentVehicleTypes.size(); k++)
			{
				if(currentVehicleTypes[k] == this->garages[i]->getVehicles()[j]->getType()[k])
				{
					possibleGarages.push_back((*this->garages[i]));
					validGarage = true;
					break;
				}
			}
			if(validGarage)
				break;
		}
	}
	return possibleGarages;
}

pair<Location,Location>GarbageManagement::calculateBestVertexes(vector<Location> locations)
{
	pair<Location,Location> bestLocations(Location(-1,pair<double,double>(0,0)), Location(-1,pair<double,double>(0,0)));
	pair<double,double> locationScores(0,0);
	for(unsigned int i = 0; i < locations.size(); i++)
	{
		double currentLocationScore = calculateScoreVertexLocations(locations[i],locations);
		if((currentLocationScore > locationScores.first) || (currentLocationScore > locationScores.second) )
		{
			double temp = (locationScores.first - locationScores.second);
			if( locationScores.first == 0 || temp < 0)
			{
				locationScores.first = currentLocationScore;
				bestLocations.first = locations[i];
			}
			else if(locationScores.second == 0 || temp > 0)
			{
				locationScores.second = currentLocationScore;
				bestLocations.second = locations[i];
			}
		}
	}
	return bestLocations;
}

/*
 * function used to calculate the "score" of a trip starting on current location
 * and visiting every other location (using getfloydWarshallShortestPath)
 */
double GarbageManagement::calculateScoreVertexLocations (Location currentLocation, vector<Location> locations)
{
	if(algorithm == 2)
	this->graph.dijkstraShortestPath(currentLocation);

	double score = 0;
	for(unsigned int i = 0; i < locations.size(); i++)
	{
		vector<Location> path;
		if(algorithm == 1)
		{
			path = this->graph.getfloydWarshallPath(currentLocation, locations[i]);
			score += calculatePathScore(path);
		}
		else
		{
			path = this->graph.getPath(currentLocation,locations[i]);
			score += calculatePathScore(path);
		}
	}
	return score;
}

vector<Location> GarbageManagement::calculateBestPath(vector<vector<Location>> paths)
{
	double score = INT_MAX;
	vector<Location> path;
	for(unsigned int i = 0; i<paths.size(); i++)
	{
		int currentScore = calculatePathScore(paths[i]);
		if(currentScore < score)
		{
			path = paths[i];
			score = currentScore;
		}
	}
	return path;
}

//doesn't take into account the situation of 2+ edges to 1 vertex
double GarbageManagement::calculatePathScore(vector<Location> path)
{
	double score = 0;
	for(unsigned int i = 0; i<path.size()-1; i++)
	{
		vector<Edge<Location>> vertexAdjEdges = this->graph.getVertex(path[i])->getAdj();
		for(unsigned int j = 0; j<vertexAdjEdges.size(); j++)
		{
			if((*vertexAdjEdges[j].getDest()) == path[i+1])
			{
				score += vertexAdjEdges[j].getWeight();
				break;
			}
		}
	}
	return score;
}

vector<Garage *> GarbageManagement::getValidGarages(Container * container)
{
	vector<Garage *> validGarages;
	garbageType type = container->getType();

	for (unsigned int i = 0; i <this->garages.size(); i++)
	{
		bool validGarage = false;
		for(unsigned int j = 0; j<this->garages[i]->getVehicles().size(); j++)
		{
			for(unsigned int k = 0; k < this->garages[i]->getVehicles()[j]->getType().size(); k++)
			{
				if(type == this->garages[i]->getVehicles()[j]->getType()[k])
				{
					validGarages.push_back(this->garages[i]);
					validGarage = true;
					break;
				}
			}
			if(validGarage)
				break;
		}
	}
	return validGarages;
}


void GarbageManagement::simulatePath(vector<vector<Location>> paths)
{
	if(algorithm == 1)
		this->graph.floydWarshallShortestPath();

	vector<vector<Location>> fullPath;
	for(unsigned int i = 0; i < paths.size(); i++)
	{
		vector<Location> path;
		for(unsigned int j = 0; j < paths[i].size()-1; j++)
		{
			vector<Location> tempPath;
			if(algorithm == 1)
			{
				tempPath = this->graph.getfloydWarshallPath((paths[i][j]),(paths[i][j+1]));
			}
			else
			{
				this->graph.dijkstraShortestPath(paths[i][j]);
				tempPath = this->graph.getPath((paths[i][j]),(paths[i][j+1]));
			}
			if(j == 0)
			{
				path = tempPath;
			}
			else
			{
				for(unsigned int k = 1; k <tempPath.size(); k++)
				{
					path.push_back(tempPath[k]);
				}
			}
		}
		fullPath.push_back(path);
	}

	for(unsigned int i = 0; i < fullPath.size(); i++)
	{
		for(unsigned int j = 0; j < fullPath[i].size(); j++)
		{
			cout << fullPath[i][j].getId() << endl;
			this->viewer->setVertexColor(fullPath[i][j].getId(),ORANGE);
			this->viewer->rearrange();
			clock_t begin = clock();
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

			while(elapsed_secs < 2)
			{
				clock_t end = clock();
				elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			}

			if(j == 0)
			{
				this->viewer->setVertexColor(fullPath[i][j].getId(),YELLOW);
			}
			else if(j == fullPath[i].size()-1)
			{
				this->viewer->setVertexColor(fullPath[i][j].getId(),GREEN);
			}
			else
			{
				this->viewer->setVertexColor(fullPath[i][j].getId(),BLUE);
			}
			this->viewer->rearrange();
		}
	}
}



void GarbageManagement::evaluateConnectivity()
{
	if(this->genericLocations.size() == 0)
	startTests();

	bool directed = false;
	for(unsigned int i = 0; i < this->graph.getVertexSet().size(); i++)
	{
		this->graph.dfsVisit(this->graph.getVertexSet()[i]);
		for(unsigned int j = 0; j < this->graph.getVertexSet().size(); j++)
		{
			if(!this->graph.getVertexSet()[j]->getVisited())
			{
				directed = true;
				break;
			}
		}
		if(directed)
			break;
	}

vector<Location> notConnectedLocations;
for(unsigned int i = 0; i < this->graph.getVertexSet().size(); i++)
{
	if(this->graph.getVertexSet()[i]->getAdj().size() == 0)
	{
		bool connected = false;
		for(unsigned int j = 0; j < this->graph.getVertexSet().size(); j++)
		{
			vector<Edge<Location>> edges = this->graph.getVertexSet()[j]->getAdj();
			for(unsigned int k = 0; k < edges.size(); k++)
			{
				if(edges[k].getDest()->getInfo().getId() == this->graph.getVertexSet()[i]->getInfo().getId())
				{
					connected = true;
					break;
				}
			}

		}
		if(!connected)
		{
			notConnectedLocations.push_back(this->graph.getVertexSet()[i]->getInfo());
			cout << "Point " << this->graph.getVertexSet()[i]->getInfo().getId() << " is impossible to reach." << endl;
		}
}
}

	if(!directed)
	{
		cout << "Graph is not directed since a depth search on a generic point returns every single node." << endl;

		for(unsigned int i = 0; i < this->graph.getVertexSet().size(); i++)
		{
			Location location = this->graph.getVertexSet()[i]->getInfo();
			vector<Edge<Location>> tempEdges = this->graph.getVertexSet()[i]->getAdj();
			Graph<Location> temp = this->graph.clone();
			temp.removeVertex(location);
			for(unsigned int j = 0; j < temp.getVertexSet().size(); j++)
			{
				bool isNotConnected = false;
				for(unsigned int k = 0; k< notConnectedLocations.size(); k++)
				{
					if(temp.getVertexSet()[j]->getInfo().getId() == notConnectedLocations[k].getId())
					{
						isNotConnected = true;
					}
				}
				if(!isNotConnected && temp.getVertexSet()[j]->getAdj().size() == 0)
				{
					cout << "Location " << location.getId() << " is an articulation point." << endl;
					break;
				}
			}
		}
	}
	else
	{
		cout << "Graph is directed since a depth search on a generic point doesn't return every single node." << endl;
		Graph<Location> temp = this->graph.clone();
		//reverse all edges
		for(unsigned int i = 0; i < temp.getVertexSet().size(); i++)
		{
			Location currentLocation = temp.getVertexSet()[i]->getInfo();
			vector<Edge<Location>> edges = temp.getVertexSet()[i]->getAdj();
			for(unsigned int j = 0; j < edges.size(); j++)
			{
				temp.removeEdge(currentLocation,edges[j].getDest()->getInfo());
				temp.addEdge(edges[j].getDest()->getInfo(), currentLocation, 0, EdgeType().DIRECTED);
			}
		}

		for(unsigned int i = 0; i<temp.getVertexSet().size(); i++)
		{
			if(temp.getVertexSet()[i]->getAdj().size() == 0)
			{
				cout << "Graph is not strongly connected in point " << temp.getVertexSet()[i]->getInfo().getId() << endl;
			}
		}
	}
}






void pre_kmp(string pattern, vector<int> & prefix)
{
	//		padrao -> string			prefixo -> vetor de ints

	int m=pattern.length();				// m -> tamanho do padrao
	prefix[0]=-1;						//primeiro elemento do prefixo é -1
	int k=-1;
	for (int q=1; q<m; q++) {			//Percorrer desde 1 ate m-1 (Ciclo executa 1 vez menos que o tamanho do padrao)
		while (k>-1 && pattern[k+1]!=pattern[q])	//Ciclo que executa enquanto k > -1 e enquanto o char de indice k+1 do padrao for diferente do char de indice q do padrao
			k = prefix[k];
		if (pattern[k+1]==pattern[q]) k=k+1;		//se o char de indice k+1 do padrao for igual ao char de indice q do padrao, k++
		prefix[q]=k;								//o char de indice q = k
	}
}

bool kmp(string text, string pattern)
{
	//	text -> string		padrao -> string
	int m=pattern.length();			// m -> tamanho do padrao
	vector<int> prefix(m);			//prefix -> vetor de ints com o mesmo tamanho que o padrao
	pre_kmp(pattern, prefix);

	int n=text.length();			// n -> tamanho de text

	int q=-1;
	for (int i=0; i<n; i++) {		//Percorrer desde 1 ate n-1 (Ciclo executa n vezes (tamanho de text)
		while (q>-1 && pattern[q+1]!=text[i])		//Ciclo que executa enquanto q > -1 e enquanto o char de indice q+1 do padrao for diferente to char de indice i de text
			q=prefix[q];
		if (pattern[q+1]==text[i])		//Se o char de indice q+1 do padrao for igual ao char de indice i do text, q++
			q++;
		if (q==m-1) {					//Se q == (m-1), informar que o padrao ovorre com desvio de i-m+1
			return true;
			q=prefix[q];
		}
	}
	return false;
}


Street * GarbageManagement::findStreetExact(string input)
{
	Street * resStreet = NULL;

	string eachStreet;
	bool isNameStreet = false;

	for(unsigned int i = 0; i < streets.size(); i++)
	{
		eachStreet = streets[i]->getName();
		isNameStreet = kmp(eachStreet, input);
		if(isNameStreet == true)
		{
			resStreet = streets[i];
			break;
		}
	}

	return resStreet;
}











Street * GarbageManagement::findStreetAproximated(string input, int distance){
	Street * resStreet = NULL;

	return resStreet;
}

vector<Street *> GarbageManagement::findAllStreetAproximated(string input, int distance){
	vector<Street *> resStreets;

	return resStreets;
}
