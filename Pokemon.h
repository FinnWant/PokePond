
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

template <typename T>
class Pokemon
{
private:
    std::string name;
    int level;
    T *health;      // Using a pointer for health
    int experience; // Experience points for leveling up

public:
    // Parameterized Constructor
    Pokemon(const std::string &name, int level, T healthValue);

    // Copy Constructor
    Pokemon(const Pokemon &other);

    // Destructor
    ~Pokemon();

    // Getters and other member functions
    std::string getName() const;
    void gainExperience(int xp);
    int requiredExperience() const;
    void levelUp();
    void evolve(const std::string &newName);
    void display() const;
    void takeDamage(int damage);
    int getAttackPower() const;

    // operators overloading- member functions
    Pokemon operator+(const Pokemon &other);
    bool operator==(const Pokemon &other) const;
    bool operator<=(const Pokemon &other) const;
    bool operator>=(const Pokemon &other) const;
    Pokemon &operator=(const Pokemon &other);
    bool operator!() const;
    Pokemon &operator++();   // Pre-increment
    Pokemon operator++(int); // Post-increment

    // Friend functions for I/O- Non-member functions
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Pokemon<U> &p);
    template <typename U>
    friend std::istream &operator>>(std::istream &is, Pokemon<U> &p);
};
// Do not make any changes above this line
//  Implement the template functions
// Your code here
//paramaterized constructor
template <class T>
Pokemon<T>::Pokemon(const std::string &name, int level, T healthValue)
{
    this->name = name;
    this->level = level;
    health = new T(1);
    *health = healthValue;
    this->experience = 0;
    std::cout << "Pokemon parameterized constructor invoked for "
              << name << std::endl;
}

//copy constuctor
template <class T>
Pokemon<T>::Pokemon(const Pokemon &other)
{
    std::cout << "pokemon copy constructor invoked for "
              << other.getName() << std::endl;
    name = other.name;
    level = other.level;
    experience = other.experience;
    health = new T(1);
    *health = *other.health;
}

//destructor
template <class T>
Pokemon<T>::~Pokemon()
{
    std::cout << "pokemon destructor invoked for "
              << this->getName() << std::endl;

    if (health != nullptr)
    {
        delete health;
    }
}

//getter func for name
template <typename T>
std::string Pokemon<T>::getName() const
{
    return name;
}

//adds experience to pokemon
template <typename T>
void Pokemon<T>::gainExperience(int xp)
{
    experience += xp;
    if (experience >= requiredExperience())
    {
        levelUp();
    }
}

//returns required ammount of experience to level up
template <typename T>
int Pokemon<T>::requiredExperience() const
{
    return level * 100;
}

//levels up pokemon
template <typename T>
void Pokemon<T>::levelUp()
{
    level += 1;
    *health += 10;
    std::cout << name << " leveled up" << std::endl;
}

//evolves pokemon
template <typename T>
void Pokemon<T>::evolve(const std::string &newName)
{
    if (newName != "")
    {
        name = newName;
        std::cout << name << " has evolved!" << std::endl;
    }
    else if (newName == "")
    {
        name = newName;
        std::cout << "Empty string: No Evolution" << std::endl;
    }
}

// STILL NEEDS TO BE WORKED ON AFTER << OPERATOR IS OVERLOADED
template <typename T>
void Pokemon<T>::display() const
{
    std::cout << *this << std::endl;
}

//takes damage ammount away from pokemon hp
template <typename T>
void Pokemon<T>::takeDamage(int damage)
{
    *health = *health - damage;
    if (*health <= 0)
    {
        *health = 0;
    }
}

//returns attack power of pokemon
template <typename T>
int Pokemon<T>::getAttackPower() const
{
    return level * 5;
}

//overloads + operator to add two pokemon together
template <typename T>
Pokemon<T> Pokemon<T>::operator+(const Pokemon &other)
{
    std::string newName = this->name + "-" + other.name;
    int newLevel = (this->level + other.level) / 2;
    T newHealth = (*this->health + *other.health) / 2;
    return Pokemon(newName, newLevel, newHealth);
}

//overloads == operator
template <typename T>
bool Pokemon<T>::operator==(const Pokemon &other) const
{
    if (this->name == other.name && this->level == other.level && *this->health == *other.health)
    {
        return true;
    }
    return false;
}

//overloads <= operator
template <typename T>
bool Pokemon<T>::operator<=(const Pokemon &other) const
{
    if (this->level <= other.level)
    {
        return true;
    }
    return false;
}

//overloads >= operator
template <typename T>
bool Pokemon<T>::operator>=(const Pokemon &other) const
{
    if (this->level >= other.level)
    {
        return true;
    }
    return false;
}

//overloads = operator
template <typename T>
Pokemon<T> &Pokemon<T>::operator=(const Pokemon &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->level = other.level;
        this->experience = other.experience;

        if (health != nullptr)
        {
            delete this->health;
        }

        this->health = new T(*other.health);
    }

    return *this;
}

//overloads ! operator
template <typename T>
bool Pokemon<T>::operator!() const
{
    if (*health <= 0)
    {
        return true;
    }
    return false;
}

//overloads post-increment
template <typename T>
Pokemon<T> &Pokemon<T>::operator++()
{
    ++level;
    return *this;
}

//overloads pre-increment
template <typename T>
Pokemon<T> Pokemon<T>::operator++(int)
{
    Pokemon<T> temp = *this;
    ++level;
    return temp;
}

//overloads extraction operator
template <typename U>
std::ostream &operator<<(std::ostream &os, const Pokemon<U> &p)
{
    os << "Pokemon Name: " << p.name << ", Level: "
       << p.level << ", Health: " << *p.health
       << ", Experience: " << p.experience;

    return os;
}

//overloads insersion operator
template <typename U>
std::istream &operator>>(std::istream &is, Pokemon<U> &p)
{
    std::string tempName = " ";
    int healthValue = 0, tempLevel = 0;
    is >> tempName >> tempLevel >> healthValue;

    while (tempLevel < 0 || healthValue < 0)
    {
        if (tempLevel < 0)
        {
            std::cout << "Invalid Level";
            is.clear();
            is.ignore(100, '\n');
            is >> tempName >> tempLevel >> healthValue;
        }
        if (healthValue < 0)
        {
            std::cout << "Invalid Health Value";
            is.clear();
            is.ignore(100, '\n');
            is >> tempName >> tempLevel >> healthValue;
        }
    }

    p.name = tempName;
    p.level = tempLevel;

    delete p.health;
    p.health = new int(10);
    *p.health = healthValue;
    return is;
}

#endif // POKEMON_H
