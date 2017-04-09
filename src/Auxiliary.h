/*
 * Auxiliary.h
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#ifndef AUXILIARY_H_
#define AUXILIARY_H_

#define TAB "	"
#define TAB_BIG "		"

#include <string>

enum garbageType {
	glass, plastic, paper, generic
};
enum locationType {
	location, garage, container, station
};
short int readUnsignedShortInt(unsigned short int first,
		unsigned short int last);

bool verifyInt(std::string temp);
bool verifyDouble(std::string temp);

int getInt();
double getDouble();
long getLong();

#endif /* AUXILIARY_H_ */
