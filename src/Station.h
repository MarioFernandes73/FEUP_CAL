/*
 * Station.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef STATION_H_
#define STATION_H_

#include "Location.h"
#include <string>

class Station : public Location{

public:
	Station(){}
	Station(std::string name, std::pair<double,double> coordinates );
	Station(long id, std::pair<double,double> coordinates);
	virtual ~Station();
};

#endif /* STATION_H_ */
