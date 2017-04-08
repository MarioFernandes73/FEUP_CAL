/*
 * ParserOsm.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Bruno
 */

#include "ParserOsm.h"


using namespace std;

void vertexParser(GarbageManagement & garbageManagement)
{
	ifstream VertexFile("Vertex.txt");

	while (!VertexFile.eof())
	{
		string line, temp;
		stringstream ss;
		long id;
		pair<double,double> coordinates;
		getline(VertexFile, line);

		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> id;
		ss.clear();
		ss.str("");

		line = line.substr(line.find(";") + 1);
		temp = temp.substr(0, line.find(";"));
		ss << temp;
		ss >> coordinates.first;
		ss.clear();
		ss.str("");


		line = line.substr(line.find(";") + 1);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> coordinates.second;
		ss.clear();
		ss.str("");

		garbageManagement.addLocation(new Location (id, coordinates));
	}
	VertexFile.close();
}


void edgesParser(GarbageManagement &garbageManagement)
{
	ifstream EdgeFile("Edges.txt");

	while (!EdgeFile.eof())
	{
		string line, temp;
		stringstream ss;
		long id;
		pair<long,long> vertexIds;
		getline(EdgeFile, line);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> id;
		ss.clear();
		ss.str("");

		line = line.substr(line.find(";") + 1);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> vertexIds.first;
		ss.clear();
		ss.str("");

		line = line.substr(line.find(";") + 1);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> vertexIds.second;
		ss.clear();
		ss.str("");

		garbageManagement.addEdge(0, vertexIds);

	}
	EdgeFile.close();

}

