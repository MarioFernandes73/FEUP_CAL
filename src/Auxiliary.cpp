/*
 * Auxiliary.cpp
 *
 *  Created on: 10 Mar 2017
 *      Author: M�rio
 */

#include <string>
#include <sstream>
#include <iostream>

#include "Auxiliary.h"

using namespace std;

short int readUnsignedShortInt(unsigned short int first, unsigned short int last)
{
	unsigned short int input;
	string temp;
	stringstream ss;

	getline(cin, temp);

	if(temp=="")
	{
		return 0;
	}

	for(unsigned int i=0; i<temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			return -1;
		}
	}

	ss << temp;
	ss >> input;

	if(first <= input && input <= last)
	return input;

	return -2;
}

int getInt()
{
	stringstream ss;
	string temp;
	int id;
	getline(cin,temp);
	ss << temp;
	ss >> id;
	return id;
}

double getDouble()
{
	stringstream ss;
	string temp;
	double id;
	getline(cin,temp);
	ss << temp;
	ss >> id;
	return id;
}
