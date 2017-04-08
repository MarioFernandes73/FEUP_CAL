/*
 * Location.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <string>
#include "Auxiliary.h"
#include <fstream>



class Location {
private:
	static long idCounter;
	long id;
	std::string name;
	std::pair<double,double> coordinates;
	locationType type;
	bool full;
public:
	Location();
	Location(int id);
	Location(std::string name, std::pair<double,double> coordinates);
	Location(int id, std::pair<double,double> coordinates);
	std::string getName();
	std::pair<double,double> getCoordinates();
	int getId() const;

	locationType getLocationType();
	void setType(locationType type);
	void setName(std::string name);

	void fillContainer();
	void clearContainer();

	virtual bool isFull();

	bool operator == (const Location &location) const;
	bool operator != (const Location &location) const;

	void setID(int id);
	virtual ~Location();
};

#endif /* LOCATION_H_ */
