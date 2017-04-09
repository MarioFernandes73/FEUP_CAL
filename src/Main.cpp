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

	// Initialization
	GarbageManagement management = GarbageManagement();

	// load files
	//vertexParser(management);
	//edgesParser(management);

	// call interface
	initialOptions(management);

	// save files
	return 0;
}
