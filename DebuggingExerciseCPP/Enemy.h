#pragma once
#include "Character.h"

class Enemy :
    public Character
{
public:
    Enemy() : Character() {}
    Enemy(const char* name, float health, float damage, float defense);
    
    //Inheritered via Character
    /// <summary>
    /// Attacks the given character using a random damage boost.
    /// </summary>
    /// <param name="other">The other character to attack.</param>
    /// <returns>The total damage dealt.</returns>
    virtual float attack(Character* other);
};

