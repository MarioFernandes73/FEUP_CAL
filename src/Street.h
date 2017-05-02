/*
 * Street.h
 *
 *  Created on: 2 May 2017
 *      Author: Mario
 */

#ifndef SRC_STREET_H_
#define SRC_STREET_H_


#include "Location.h"



class Street {
private:
	static long idCounterStreet;
	long id;
	std::string name;
	Location * vertex1;
	Location * vertex2;
public:
	Street(std::string name, Location * vertex1, Location * vertex2);
	long getId();
	static long getCurrentId(){return idCounterStreet;}
	static void incCurrentId(){idCounterStreet++;}
	std::string getName();
	Location * getLocation1();
	Location * getLocation2();
	virtual ~Street();
};

#endif /* SRC_STREET_H_ */
