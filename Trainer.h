
#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include "Pokemon.h"

class Trainer {
private:
    std::string trainerName;
    std::vector<Pokemon<int>*> pokemons; // Dynamic allocation of Pokemon

public:
    // Constructor
    Trainer(const std::string& name);
    
    // Destructor
    ~Trainer();

    // Add Pokemon to trainer's collection
    void addPokemon(Pokemon<int>* pokemon);
    
    // Display trainer's Pokemon
    void displayPokemons() const;
    
    // Function to initiate a battle
    void battle(Pokemon<int>& attacker, Pokemon<int>& defender);
};

#endif // TRAINER_H
