/*
 * Location.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <string>
#include <fstream>



class Location {
private:
	static int idCounter;
	int id;
	std::string name;
	std::pair<double,double> coordinates;
public:
	Location(std::string name, std::pair<double,double> coordinates);
	Location(int id, std::pair<double,double> coordinates);
	std::string getName();
	std::pair<double,double> getCoordinates();
	int getId();

	bool operator == (const Location &m) const;
	virtual ~Location();
};

#endif /* LOCATION_H_ */
