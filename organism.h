/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#ifndef ORGANISM_H
#define ORGANISM_H

class organism
{
public:
	organism(double = 1, double = 0);
	virtual void simulateWeek();
	void assignRate(double);
	void alterSize(double);
	void death();
	double getSize() const;
	double getRate() const;
	bool isAlive() const;
	virtual ~organism();
protected:
	double growthRate;
private:
	double size;
};

#endif // ORGANISM_H
