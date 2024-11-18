/*
Name: Finnaginn Wantland, NSHE: 2002196609,
CLASS-SECTION: CS202, ASSIGNMENT: 6
Purpose: Multiple classes, Composition, Templates, Operator Overloading
Description: Implementing Pokemon Mechanics:Templates and
Operator Overloading
Input: GameImp.cpp is a Driver class in this assignment. Objects of
different classes are declared in GameImp.cpp using constructors, and
other functions.
What to do?: This system manages pokemon's information like name, level,
health,  and experience. Implement the function prototypes in Pokemon.h
and implement the functions in Trainer.h
Output: You write the output on the terminal itself. You print all valid
and invalid entries;
print error messages for invalid entries accordingly.
Check example output for more details.
*/
#include "Trainer.h"
#include <iostream>

using namespace std;

Trainer::Trainer(const std::string &name)
{
    trainerName = name;
    cout << "Trainer constructor invoked for " << trainerName << endl;
}

Trainer::~Trainer()
{
    int count = pokemons.size();
    for (int i = 0; i < count; i++)
    {
        if(pokemons[i] != nullptr)
        {
            delete pokemons[i];
        }
    }
    
    //pokemons.clear();
    cout << "Trainer destructor invoked for " << trainerName << endl;
}

void Trainer::addPokemon(Pokemon<int> *pokemon)
{
    pokemons.push_back(pokemon);
}

void Trainer::displayPokemons() const
{
    int count = pokemons.size();
    cout << trainerName << "'s Pokemon:" << endl;
    for (int i = 0; i < count; i++)
    {
        if (pokemons[i] != nullptr)
        {
            pokemons[i]->display();
        }
    }
}

void Trainer::battle(Pokemon<int> &attacker, Pokemon<int> &defender)
{
    int totalDamage = attacker.getAttackPower();
    defender.takeDamage(totalDamage);
    cout << attacker.getName() << " attacks " << defender.getName()
         << " for " << totalDamage << " damage." << endl;

    if (!defender == true)
    {
        attacker.gainExperience(50);
        cout << attacker.getName() << " defeated "
             << defender.getName() << "!" << endl;
    }
}