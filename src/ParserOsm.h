/*
 * ParserOsm.h
 *
 *  Created on: 28/03/2017
 *      Author: Bruno
 */

#ifndef SRC_PARSEROSM_H_
#define SRC_PARSEROSM_H_

#include "GarbageManagement.h"
#include <string>
#include <sstream>
#include <fstream>

void vertexParser(GarbageManagement &garbageManagement, bool value);
void edgesParser(GarbageManagement &garbageManagement);

void saveVertexes(GarbageManagement &garbageManagement);
void saveEdges(GarbageManagement &garbageManagement);

#endif /* SRC_PARSEROSM_H_ */
