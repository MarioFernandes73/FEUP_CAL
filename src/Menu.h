/*
 * Menu.h
 *
 *  Created on: 14 Mar 2017
 *      Author: Mário
 */

#ifndef MENU_H_
#define MENU_H_

#include "GarbageManagement.h"

void initialOptions(GarbageManagement & management);
void vertexOptions(GarbageManagement & management);
void edgeOptions(GarbageManagement & management);
void vehicleOptions(GarbageManagement & management);
void settingsOptions(GarbageManagement & management);

short int initialMenu();
short int vertexMenu();
short int edgeMenu();
short int vehicleMenu();
short int settingsMenu();

#endif /* MENU_H_ */
