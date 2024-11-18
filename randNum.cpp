/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#include "randNum.h"
#include <string>
using namespace std;

// TODO: Write the implementation here...

randNum::randNum(string filename) : infile(filename){
    ifstream infile(filename);
}

int randNum::getNextRand(){
    int number = 0;
    infile >> number;
    return number;
}

randNum::~randNum(){
    infile.close();
}
