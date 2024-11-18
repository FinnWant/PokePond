/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#include "herbivore.h"
#include <iostream>
using namespace std;

// TODO: Write the implementation here...
herbivore::herbivore(double initSize, double initRate, double initNeed):animal(initSize, initRate, initNeed){
}

const double herbivore::PORTION = 0.5;
const double herbivore::MAX_FRACTION = 0.1;

void herbivore::nibble(plant& meal){
    double amount = (PORTION * meal.getSize());
    if(amount > MAX_FRACTION * totalNeed()){
        amount = MAX_FRACTION * totalNeed();
    }
    if(amount > stillNeed()){
        amount = stillNeed();
    }
    eat(amount);
    meal.nibbledOn(amount);
}

herbivore::~herbivore(){
    cout << "FISH DIED" << endl;
}