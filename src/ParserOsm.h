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


void vertexParser(GarbageManagement &theGarbageManagement);

void edgesParser(GarbageManagement &theGarbageManagement);



#endif /* SRC_PARSEROSM_H_ */
