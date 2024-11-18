/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#include "plant.h"
#include <iostream>
using namespace std;

// TODO: Write the implementation here...

plant::plant(double initSize, double initRate):organism(initSize, initRate){
};

void plant::nibbledOn(double amount){
    double currentSize = getSize();
    
    if(amount > currentSize){
        alterSize(-getSize());
    }
    else{
        alterSize(-amount);
    }
}

plant::~plant(){
    cout << "PLANT DIED" << endl;
}
