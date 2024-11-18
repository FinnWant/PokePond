/*
 * Name: Finnagin Wantland, 2002196609, 1001, Assignment 5
 * Description: Assignment 5 Ash goes Fishing
 * Input: csv file and command line arguements
 * Output: end of the simulation data
 */
#include "animal.h"

// TODO: Write the implementation here...
animal::animal(double initSize, double initRate, double initNeed):organism(initSize, initRate){
    needThisWeek = initNeed;
    eatenThisWeek = 0;
}

void animal::assignNeed(double newNeed){
    needThisWeek = newNeed;
}

void animal::eat(double amount){
    eatenThisWeek += amount;
}

void animal::simulateWeek(){
    if(stillNeed() > 0){
        double temp = getRate();
        if(temp > 0){
            temp = temp * -1.0;
        }
        assignRate(temp);
    }
    if(stillNeed() == 0){
        double temp = getRate();
        if(temp < 0){
            temp = temp * -1.0;
        }
        assignRate(temp);
    }

    organism::simulateWeek();

    eatenThisWeek = 0.0;

    if(!isAlive()){
        death();
    }
}

double animal::stillNeed() const{
    if(eatenThisWeek >= needThisWeek){
        return 0;
    }
    return needThisWeek - eatenThisWeek;
}

double animal::totalNeed() const{
    return needThisWeek;
}

animal::~animal(){
    needThisWeek = 0;
    eatenThisWeek = 0;
}