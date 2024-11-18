
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
