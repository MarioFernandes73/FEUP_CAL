/*
 * ParserOsm.cpp
 *
 *  Created on: 28/03/2017
 *      Author: Bruno
 */

#include "ParserOsm.h"

using namespace std;

void vertexParser(GarbageManagement & garbageManagement, bool value) {
	ifstream VertexFile("Vertex.txt");

	while (!VertexFile.eof()) {
		string line, temp;
		stringstream ss;
		long id;
		long tempId;
		pair<double, double> coordinates;
		getline(VertexFile, line);

		if (line == "")
			break;

		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> id;
		ss.clear();
		ss.str("");

		line = line.substr(line.find(";") + 1);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> coordinates.first;
		ss.clear();
		ss.str("");
		if (value) {
			tempId = coordinates.first * 100000;
			coordinates.first = tempId % 1000;
		}

		line = line.substr(line.find(";") + 1);
		temp = line.substr(0, line.find(";"));
		ss << temp;
		ss >> coordinates.second;
		ss.clear();
		ss.str("");
		if (value) {
			tempId = coordinates.second * 100000;
			coordinates.second = tempId % 1000;
		}

		garbageManagement.addLocation(new Location(id, coordinates));
	}
	VertexFile.close();
}

void edgesParser(GarbageManagement &garbageManagement) {
	ifstream EdgeFile("Edges.txt");

	while (!EdgeFile.eof()) {
		string line, temp;
		stringstream ss;
		long id;
		pair<long, long> vertexIds;
		getline(EdgeFile, line);

		if (line == "")
			break;

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

		size_t found = line.find(";");
		if(found!=string::npos){
			line = line.substr(line.find(";") + 1);
			garbageManagement.addEdge(0, vertexIds, line.substr(0, line.find(";")));
		} else {
			garbageManagement.addEdge(0, vertexIds);
		}
	}
	EdgeFile.close();
}

void saveVertexes(GarbageManagement &garbageManagement) {
	ofstream VertexFile("Vertex.txt");

	for (unsigned int i = 0; i < garbageManagement.getGenericLocations().size();
			i++) {
		Location * location = garbageManagement.getGenericLocations()[i];
		VertexFile << location->getId() << ";"
				<< location->getCoordinates().first << ";"
				<< location->getCoordinates().second << endl;
	}

	for (unsigned int i = 0; i < garbageManagement.getGarages().size(); i++) {
		Location * location = garbageManagement.getGarages()[i];
		VertexFile << location->getId() << ";"
				<< location->getCoordinates().first << ";"
				<< location->getCoordinates().second << endl;
	}

	for (unsigned int i = 0; i < garbageManagement.getContainers().size();
			i++) {
		Location * location = garbageManagement.getContainers()[i];
		VertexFile << location->getId() << ";"
				<< location->getCoordinates().first << ";"
				<< location->getCoordinates().second << endl;
	}

	for (unsigned int i = 0; i < garbageManagement.getStations().size(); i++) {
		Location * location = garbageManagement.getStations()[i];
		VertexFile << location->getId() << ";"
				<< location->getCoordinates().first << ";"
				<< location->getCoordinates().second << endl;
	}

}

void saveEdges(GarbageManagement &garbageManagement) {
	ofstream EdgeFile("Edges.txt");

	for(unsigned int i = 0; i< garbageManagement.getStreets().size(); i++)
	{
		Street * tempStreet = garbageManagement.getStreets()[i];
		EdgeFile << tempStreet->getId() << ";" << tempStreet->getLocation1()->getId() << ";"
				<< tempStreet->getLocation2()->getId() << ";" << tempStreet->getName() << endl;
	}
}
