//============================================================================
// Name        : Projeto1_Cal.cpp
// Author      :
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GarbageManagement.h"
#include "Menu.h"
#include "ParserOsm.h"

int main() {

	// variables declaration
	GarbageManagement management = GarbageManagement();

	// load files
	//vertexParser(management);
	//edgesParser(management);

	// Initialisation

	// call interface
	initialOptions(management);

	// save files
	return 0;
}
