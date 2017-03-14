/*
 * Container.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Location.h"
#include "Auxiliary.h"

class Container : public Location {
private:
	garbageType type;
	double quantity;
public:
	Container();
	virtual ~Container();
};

#endif /* CONTAINER_H_ */
