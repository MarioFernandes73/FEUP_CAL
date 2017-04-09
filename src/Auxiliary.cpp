/*
 * Auxiliary.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: Mário
 */

#include <string>
#include <sstream>
#include <iostream>

#include "Auxiliary.h"
#include "MyExceptions.h"

using namespace std;

bool verifyInt(string temp) {
	if (temp == "")
		return false;

	for (unsigned int i = 0; i < temp.size(); i++) {
		if (!isdigit(temp[i]))
			return false;
	}

	return true;
}

bool verifyDouble(string temp) {
	bool dot = false;
	if (temp == "")
		return false;

	for (unsigned int i = 0; i < temp.size(); i++) {
		if (!isdigit(temp[i]))
			return false;
		else if (temp[i] == '.')
			if (!dot)
				dot = true;
			else
				return false;
		else
			return false;
	}
	return true;
}

short int readUnsignedShortInt(unsigned short int first,
		unsigned short int last) {
	unsigned short int input;
	string temp;
	stringstream ss;

	getline(cin, temp);

	if (!verifyInt(temp))
		throw NoValidEntryException();

	ss << temp;
	ss >> input;

	if (first <= input && input <= last)
		return input;

	throw OutOfBondsException();
}

int getInt() {
	stringstream ss;
	string temp;
	int id;
	getline(cin, temp);
	if (!verifyInt(temp))
		throw NoValidEntryException();
	ss << temp;
	ss >> id;
	return id;
}

double getDouble() {
	stringstream ss;
	string temp;
	double id;
	getline(cin, temp);
	if (!verifyDouble(temp))
		throw NoValidEntryException();
	ss << temp;
	ss >> id;
	return id;
}

long getLong() {
	stringstream ss;
	string temp;
	long id;
	getline(cin, temp);
	if (!verifyInt(temp))
		throw NoValidEntryException();
	ss << temp;
	ss >> id;
	return id;
}
