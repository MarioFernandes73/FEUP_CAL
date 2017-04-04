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
	long theID;
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
	cout << theFirstLocation.getId() << endl;
	cout << theFirstLocation.getCoordinates().first << endl;
	cout << theFirstLocation.getCoordinates().second << endl;
	cout << "Size: " << theGarbageManagement.getGraph().getVertexSet().size() << endl;

	int counter = 0;
	while (!VertexFile.eof())
	{
		counter++;
		string eachLine;
		getline(VertexFile, eachLine);
		string stringID2 = eachLine.substr(0, eachLine.find(";"));
		stringstream thestringID2;
		thestringID2 << stringID2;
		long theID2;
		thestringID2 >> theID2;
		thestringID2.clear();
		thestringID2.str("");

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringLatitudeDegrees2 = eachLine.substr(0, eachLine.find(";"));
		stringstream thelatitudeDegrees2;
		thelatitudeDegrees2 << stringLatitudeDegrees2;
		double LatitudeDegrees2;
		thelatitudeDegrees2 >> LatitudeDegrees2;
		thelatitudeDegrees2.clear();
		thelatitudeDegrees2.str("");

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringLongitudeDegrees2 = eachLine.substr(0, eachLine.find(";"));
		stringstream theLongitudeDegrees2;
		theLongitudeDegrees2 << stringLongitudeDegrees2;
		double LongitudeDegrees2;
		theLongitudeDegrees2 >> LongitudeDegrees2;
		theLongitudeDegrees2.clear();
		theLongitudeDegrees2.str("");

		pair <double, double> thePair2 (LatitudeDegrees2, LongitudeDegrees2);
		Location theFirstLocation2(theID2, thePair2);
		theGarbageManagement.getGraph().addVertex(theFirstLocation2);
	}
	cout << counter;
	VertexFile.close();

	//theGarbageManagement.getGraph().getNumVertex();
	cout << "Size: " << theGarbageManagement.getGraph().getVertexSet().size() << endl;
}


void getEdgesParser(GarbageManagement &theGarbageManagement)
{
	ifstream EdgeFile("Edges.txt");

	string firstLine;
	getline(EdgeFile, firstLine);
	string stringID = firstLine.substr(0, firstLine.find(";"));
	stringstream thestringID;
	thestringID << stringID;
	long theID;
	thestringID >> theID;

	firstLine = firstLine.substr(firstLine.find(";") + 2);
	string stringFirstVertexId = firstLine.substr(0, firstLine.find(";"));
	stringstream thefirstVertexId;
	thefirstVertexId << stringFirstVertexId;
	long FirstVertexId;
	thefirstVertexId >> FirstVertexId;

	firstLine = firstLine.substr(firstLine.find(";") + 2);
	string stringSecondVertexId = firstLine.substr(0, firstLine.find(";"));
	stringstream thesecondVertexId;
	thesecondVertexId << stringSecondVertexId;
	long SecondVertexId;
	thesecondVertexId >> SecondVertexId;

	//Location firstVertex(FirstVertexId);
	//Location secondVertex(SecondVertexId);
	//theGarbageManagement.getGraph().addEdge(firstVertex, secondVertex, 0);

	while (!EdgeFile.eof())
	{
		string eachLine;
		getline(EdgeFile, eachLine);
		string stringID2 = eachLine.substr(0, eachLine.find(";"));
		stringstream thestringID2;
		thestringID2 << stringID2;
		long theID2;
		thestringID2 >> theID2;
		thestringID2.clear();
		thestringID2.str("");

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringFirstVertexId2 = eachLine.substr(0, eachLine.find(";"));
		stringstream thefirstVertexId2;
		thefirstVertexId2 << stringFirstVertexId2;
		long FirstVertexId2;
		thefirstVertexId2 >> FirstVertexId2;
		thefirstVertexId2.clear();
		thefirstVertexId2.str("");

		eachLine = eachLine.substr(eachLine.find(";") + 2);
		string stringSecondVertexId2 = eachLine.substr(0, eachLine.find(";"));
		stringstream thesecondVertexId2;
		thesecondVertexId2 << stringSecondVertexId2;
		long SecondVertexId2;
		thesecondVertexId2 >> SecondVertexId2;
		thesecondVertexId2.clear();
		thesecondVertexId2.str("");

		//Location firstVertex2(FirstVertexId2);
		//Location secondVertex2(SecondVertexId2);
		//theGarbageManagement.getGraph().addEdge(firstVertex2, secondVertex2, 0);
	}
	EdgeFile.close();

}

