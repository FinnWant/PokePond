
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
