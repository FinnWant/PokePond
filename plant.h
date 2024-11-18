/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#ifndef PLANT_H
#define PLANT_H

#include "organism.h"

class plant : public organism
{
public:
	plant(double = 1, double = 0);
  	void nibbledOn(double);
	~plant();
};

#endif // PLANT_H