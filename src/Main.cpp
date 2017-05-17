//============================================================================
// Name        : Projeto1_Cal.cpp
// Author      :
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Auxiliary.h"
#include "GarbageManagement.h"
#include "Menu.h"
#include "ParserOsm.h"

int main() {

	// Initialization
	GarbageManagement management = GarbageManagement();

	// load files
	cout << "Would you like to load vertexes and edges?" << endl;
//	if (confirm()) {
		cout << "Is this your first time running these files?" << endl;
		bool value = confirm();
		vertexParser(management, value);
		edgesParser(management);
//	}


	//Street * temp = management.findStreetExact("t s");
	//cout << temp->getName() << endl;

	Street * temp = management.findStreetAproximated("az",0);
	cout << temp->getName() << endl;

	// call interface
	initialOptions(management);

	//management.findStreetAproximated("")

	// save files
	cout << "Would you like to save vertexes and edges?" << endl;
	/*if (confirm()) {
		saveVertexes(management);
		saveEdges(management);
	}
*/
	return 0;
}
