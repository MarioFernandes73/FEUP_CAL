/*
 * GarbageManagement.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: M�rio
 */

#include "GarbageManagement.h"

GarbageManagement::GarbageManagement() {
	this->viewer = new GraphViewer(640,480,false);
	this->viewer->createWindow(640, 480);
}

GarbageManagement::~GarbageManagement() {
	// TODO Auto-generated destructor stub
}

