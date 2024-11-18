
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
