/*
 * GarbageManagement.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "GarbageManagement.h"
#include "edgetype.h"

GarbageManagement::GarbageManagement() {
//	this->viewer = new GraphViewer(640,480,false);
//	this->viewer->createWindow(640, 480);
//	this->viewer->defineVertexColor("blue");
//	this->viewer->defineEdgeColor("black");
}

GarbageManagement::~GarbageManagement() {
	// TODO Auto-generated destructor stub
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

Container * GarbageManagement::getContainer(int id)
{
	for(unsigned int i = 0; i < this->containers.size(); i++)
	{
		if(this->containers[i]->getId() == id)
			return containers[i];
	}
	return NULL;
}

void GarbageManagement::addEdge(double weight, pair<int,int> vertexesCoord)
{
	Location * sourceLocation = getLocation(vertexesCoord.first);
	Location * destLocation = getLocation(vertexesCoord.second);
	this->graph.addEdge((*sourceLocation), (*destLocation), weight);
	this->viewer->addEdge(0,sourceLocation->getId(), destLocation->getId(),EdgeType().DIRECTED);
	this->viewer->rearrange();
}

void GarbageManagement::shortestPathSingleContainer(int id)
{
	// get container's location
	for(int i = 0; i< this->containers.size(); i++)
	{
	//	if()
		{

		}
	}

	// get container's vertex
	//this->graph.getVertex();

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
