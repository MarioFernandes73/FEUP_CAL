/*
 * ParserOsm.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Bruno
 */

#include "ParserOsm.h"


using namespace std;

void getVertexParser(GarbageManagement &theGarbageManagement)
{
	ifstream VertexFile("Vertex.txt");

	string firstLine;
	getline(VertexFile, firstLine);
	string stringID = firstLine.substr(0, firstLine.find(";"));
	stringstream thestringID;
	thestringID << stringID;
	int theID;
	thestringID >> theID;

	firstLine = firstLine.substr(firstLine.find(";") + 2);
	string stringLatitudeDegrees = firstLine.substr(0, firstLine.find(";"));
	stringstream thelatitudeDegrees;
	thelatitudeDegrees << stringLatitudeDegrees;
	double LatitudeDegrees;
	thelatitudeDegrees >> LatitudeDegrees;

	firstLine = firstLine.substr(firstLine.find(";") + 2);
	string stringLongitudeDegrees = firstLine.substr(0, firstLine.find(";"));
	stringstream theLongitudeDegrees;
	theLongitudeDegrees << stringLongitudeDegrees;
	double LongitudeDegrees;
	theLongitudeDegrees >> LongitudeDegrees;

	pair <double, double> thePair (LatitudeDegrees, LongitudeDegrees);
	Location theFirstLocation(theID, thePair);
	theGarbageManagement.getGraph().addVertex(theFirstLocation);

	while (!VertexFile.eof())
	{
		string eachLine;
		getline(VertexFile, eachLine);
		string stringID = eachLine.substr(0, eachLine.find(";"));
		stringstream thestringID;
		thestringID << stringID;
		int theID;
		thestringID >> theID;

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringLatitudeDegrees = eachLine.substr(0, eachLine.find(";"));
		stringstream thelatitudeDegrees;
		thelatitudeDegrees << stringLatitudeDegrees;
		double LatitudeDegrees;
		thelatitudeDegrees >> LatitudeDegrees;

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringLongitudeDegrees = eachLine.substr(0, eachLine.find(";"));
		stringstream theLongitudeDegrees;
		theLongitudeDegrees << stringLongitudeDegrees;
		double LongitudeDegrees;
		theLongitudeDegrees >> LongitudeDegrees;

		pair <double, double> thePair (LatitudeDegrees, LongitudeDegrees);
		Location theFirstLocation(theID, thePair);
		theGarbageManagement.getGraph().addVertex(theFirstLocation);
	}
	VertexFile.close();
}

