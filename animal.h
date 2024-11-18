/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

class animal : public organism
{
public:
	animal(double = 1, double = 0, double = 0);
	void assignNeed(double);
	void eat(double);
	void simulateWeek();
	double stillNeed() const;
	double totalNeed() const;
	~animal();
private:
	double needThisWeek;
	double eatenThisWeek;
};

#endif // ANIMAL_H