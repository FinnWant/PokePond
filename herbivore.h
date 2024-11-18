/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "animal.h"
#include "plant.h"

class herbivore : public animal
{
public:
	static const double PORTION;  
	static const double MAX_FRACTION;
	herbivore(double = 1, double = 0, double = 0);
	void nibble(plant&);
	~herbivore();
};

#endif // HERBIVORE_H