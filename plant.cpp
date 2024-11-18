
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
