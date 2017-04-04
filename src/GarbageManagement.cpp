/*
 * GarbageManagement.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "GarbageManagement.h"
#include "edgetype.h"
#include <sstream>
#include <algorithm>

int GarbageManagement::edgeCounter=0;
const int typeGarage = 1;
const int typeContainer = 2;
const int typeStation = 3;

GarbageManagement::GarbageManagement() {
//	this->viewer = new GraphViewer(640,480,false);
//	this->viewer->createWindow(640, 480);
//	this->viewer->defineVertexColor("blue");
//	this->viewer->defineEdgeColor("black");
}

GarbageManagement::~GarbageManagement() {
	// TODO Auto-generated destructor stub
}

void GarbageManagement::addLocation(Location * location)
{
	this->genericLocations.push_back(location);
	this->graph.addVertex((*location));
	this->viewer->addNode(location->getId(),location->getCoordinates().first, location->getCoordinates().second);
	this->viewer->rearrange();
}

void GarbageManagement::addStation(Station * station)
{
	this->stations.push_back(station);
	this->graph.addVertex((*station));
	this->viewer->addNode(station->getId(),station->getCoordinates().first, station->getCoordinates().second);
	this->viewer->rearrange();
}

void GarbageManagement::addContainer(Container * container)
{
	this->containers.push_back(container);
	this->graph.addVertex((*container));
	this->viewer->addNode(container->getId(),container->getCoordinates().first, container->getCoordinates().second);
	this->viewer->rearrange();
}

void GarbageManagement::addGarage(Garage * garage)
{
	this->garages.push_back(garage);
	this->graph.addVertex((*garage));
	this->viewer->addNode(garage->getId(),garage->getCoordinates().first, garage->getCoordinates().second);
	this->viewer->rearrange();
}

void GarbageManagement::removeStation(Station * station){
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

void GarbageManagement::removeContainer(Container * container){
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

void GarbageManagement::removeGarage(Garage * garage){
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

Location * GarbageManagement::getLocation(int id)
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

Location * GarbageManagement::getGenericLocation(int id)
{
	for(unsigned int i = 0; i < this->genericLocations.size(); i++)
	{
		if(this->genericLocations[i]->getId() == id)
			return genericLocations[i];
	}
	return NULL;
}

Station * GarbageManagement::getStation(int id)
{
	for(unsigned int i = 0; i < this->stations.size(); i++)
	{
		if(this->stations[i]->getId() == id)
			return stations[i];
	}
	return NULL;
}

Garage * GarbageManagement::getGarage(int id)
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


Container * GarbageManagement::getContainer(int id)
{
	for(unsigned int i = 0; i < this->containers.size(); i++)
	{
		if(this->containers[i]->getId() == id)
			return containers[i];
	}
	return NULL;
}

Graph<Location> GarbageManagement::getGraph()
{
	return this->graph;
}

void GarbageManagement::addEdge(double weight, pair<int,int> vertexesCoord)
{
	Location * sourceLocation = getLocation(vertexesCoord.first);
	Location * destLocation = getLocation(vertexesCoord.second);
	this->graph.addEdge((*sourceLocation), (*destLocation), weight);
	this->viewer->addEdge(edgeCounter,sourceLocation->getId(), destLocation->getId(),EdgeType().DIRECTED);
	this->viewer->rearrange();
	edgeCounter++;
}

void GarbageManagement::startTests()
{
	/*
	 * TESTS
	 */

	Garage * l0 = new Garage("ola",pair<double,double>(100,100));
	Garage * l1 = new Garage("ola",pair<double,double>(500,100));
	Location * l2 = new Location("ola",pair<double,double>(250,100));
	Container * l3 = new Container("ola",pair<double,double>(200,200), garbageType::glass,1);
	Container * l4 = new Container("ola",pair<double,double>(400,200), garbageType::glass,1);
	Container * l5 = new Container("ola",pair<double,double>(300,300), garbageType::glass,1);
	Station * l6 = new Station("ola",pair<double,double>(100,500));
	Station * l7 = new Station("ola",pair<double,double>(500,500));

	l3->fillContainer();
	l4->fillContainer();
	l5->fillContainer();


	this->addGarage(l0);
	this->addGarage(l1);
	this->addLocation(l2);
	this->addContainer(l3);
	this->addContainer(l4);
	this->addContainer(l5);
	this->addStation(l6);
	this->addStation(l7);

	for(unsigned int i = 0; i<this->garages.size(); i++)
	{
		this->garages[i]->addVehicle(new Vehicle("as",garbageType::glass,500));
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
void GarbageManagement::collectGarbage()
{
	vector<vector<Location>> paths;
	resetVehicles();
	startTests();

	//run floydWarshallShortestPath to map the distances of the vertexes
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
		cout << "NOVO VEICULO" << endl;
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
		Vehicle * currentVehicle = getBestVehicle(bestGarage);

		//move to first best vertex
		currentVehicle->moveTo(startEndVertexes.first.getCoordinates().first, startEndVertexes.first.getCoordinates().second);
		currentPath.push_back(startEndVertexes.first);
		cout << "OIX" << endl;
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
				cout << "OI" << endl;
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

	for(unsigned int i = 0; i < paths.size(); i++)
	{
		for(unsigned int j = 0; j < paths[i].size(); j++)
		{
			cout << paths[i][j].getId() << endl;
		}
	}
	cout << "WE DID IT!" << endl;
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
	Station * bestStation;
	Location vehicleLocation = (*this->getContainer(vehicle->getCurrentCoordinates()));
	double score = INT_MAX;
	for(unsigned int i = 0; i< this->stations.size(); i++)
	{
		double currentScore = this->calculatePathScore(this->graph.getfloydWarshallPath((vehicleLocation),(*this->stations[i])));
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

Vehicle * GarbageManagement::getBestVehicle(Garage garage)
{
	double score = 0;
	Vehicle * bestVehicle = NULL;
	for(unsigned int i = 0; i < garage.getVehicles().size(); i++)
	{
		if(!garage.getVehicles()[i]->isFull())
		{
			double currentScore = garage.getVehicles()[i]->getCapacity();
			if(currentScore > score)
			{
				bestVehicle = garage.getVehicles()[i];
				score = currentScore;
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
			//score based on weight
			double currentScore = this->calculatePathScore(this->graph.getfloydWarshallPath((*currentLocation),locations[i]));

			if(currentScore < minScore)
			{
				minScore = currentScore;
				bestLocation = locations[i];
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
		// if the current garage has a vehicle that has the possibility of collecting the garbage on first vertex, iterate through it
		if(garagesHasPossibleVehicle(possibleGarages[i],startEndVertexes.first))
		{
			vector<Location> pathGarageVertex = this->graph.getfloydWarshallPath(possibleGarages[i],startEndVertexes.first);
			garageVertexesScores1.push_back(calculatePathScore(pathGarageVertex));
		}
		else	//add placeholder to the vector
		{
			garageVertexesScores1.push_back(INT_MAX);
		}
		if((startEndVertexes.second.getId() != -1) && garagesHasPossibleVehicle(possibleGarages[i],startEndVertexes.second))
		{
			vector<Location> pathGarageVertex = this->graph.getfloydWarshallPath(possibleGarages[i],startEndVertexes.second);
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
			if( locationScores.first == 0 || temp > 0)
			{
				locationScores.first = currentLocationScore;
				bestLocations.first = locations[i];
			}
			else if(locationScores.second == 0 || temp < 0)
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
	double score = 0;
	for(unsigned int i = 0; i < locations.size(); i++)
	{
		vector<Location> path = this->graph.getfloydWarshallPath(currentLocation, locations[i]);
		score += calculatePathScore(path);
	}
	return score;
}


void GarbageManagement::shortestPathSingleContainer(int id)
{
	string temp;
	//getline(cin,temp);

	// get container
	Container * container = this->getContainer(id);

	// get garages that have valid vehicles
	vector<Garage *> validGarages = this->getValidGarages(container);

	vector<vector<Location>> paths;
	//calculate the closest garage to the container
	for(unsigned int i = 0; i <validGarages.size(); i++)
	{
		this->graph.dijkstraShortestPath((*validGarages[i]));
		paths.push_back(this->graph.getPath((*validGarages[i]),(*container)));
	}

	//calculate the closest garage to the container
	vector<Location> bestGarageContainerPath = calculateBestPath(paths);

	//calculate the closest station to the container
	vector<Location> bestContainerStationPath = calculateClosestStation((*container));

	cout << "GARAGE TO CONTAINER" << endl;
	for(unsigned int  i = 0; i< bestGarageContainerPath.size(); i++)
	{
		cout << bestGarageContainerPath[i].getId() << endl;
	}

	cout << "CONTAINER TO STATION" << endl;
	for(unsigned int i = 0; i < bestContainerStationPath.size(); i++)
	{
		cout << bestContainerStationPath[i].getId() << endl;
	}
	cout << "END" << endl;
	exit(0);
}

vector<Location> GarbageManagement::calculateClosestStation(Location location)
{
	this->graph.dijkstraShortestPath(location);
	vector<vector<Location>> paths;
	for(unsigned int i = 0; i < this->stations.size(); i++)
	{
		paths.push_back(this->graph.getPath(location,(*this->stations[i])));
	}

	return calculateBestPath(paths);
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

void GarbageManagement::addVehicle(int id, Vehicle * vehicle)
{
	Garage * garage = getGarage(id);
	if(garage == NULL)
	{
		//throw exception...
	}

	garage->addVehicle(vehicle);

}
