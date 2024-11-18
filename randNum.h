/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#ifndef RAND_NUM_H
#define RAND_NUM_H

#include <fstream>
using namespace std;

class randNum
{
public:
    randNum(string);
    ~randNum();
    int getNextRand();
private:
    ifstream infile;
};

#endif // RAND_NUM_H