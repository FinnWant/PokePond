
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
