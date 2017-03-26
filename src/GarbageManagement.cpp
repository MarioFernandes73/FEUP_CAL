/*
 * GarbageManagement.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include "GarbageManagement.h"

GarbageManagement::GarbageManagement() {
	this->viewer = new GraphViewer(640,480,false);
	this->viewer->createWindow(640, 480);
	this->viewer->defineVertexColor("blue");
	this->viewer->defineEdgeColor("black");
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
