/*
 * Location.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <string>

class Location {
private:
	std::string nome;
	std::pair<int,int> coordinates;
public:
	Location();
	virtual ~Location();
};

#endif /* LOCATION_H_ */
