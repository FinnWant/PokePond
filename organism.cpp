
#include "organism.h"

// TODO: Write the implementation here...
organism::organism(double initalSize, double initialRate)
{
    size = initalSize;
    growthRate = initialRate;
}

void organism::simulateWeek()
{
    size += growthRate;
}

void organism::assignRate(double newRate)
{
    growthRate = newRate;
}

void organism::alterSize(double amount)
{
    size += amount;
}

void organism::death()
{
    growthRate = 0;
    size = 0;
}

double organism::getSize() const
{
    return size;
}

double organism::getRate() const
{
    return growthRate;
}

bool organism::isAlive() const
{
    if (size > 0)
    {
        return true;
    }
    return false;
}

organism::~organism()
{
    growthRate = 0;
    size = 0;
}
