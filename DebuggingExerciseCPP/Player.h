#pragma once
#include "Item.h"
#include "Character.h"

class Player :
     public Character
{
public:
    Player() : Character() {}
    Player(const char* name, float health, float damage, float defense) :
        Character(name, health, damage, defense) {};

    /// <summary>
    /// Adds the given item's stat boost to this player's total damage.
    /// </summary>
    /// <param name="item">The players new weapon.</param>
    void equipWeapon(Item item) { m_weapon = item; }

    /// <summary>
    /// Adds the given item's stat boost to this player's total defense.
    /// </summary>
    /// <param name="item">The player's new defense item</param>
    void equipShield(Item item) { m_shield = item; }

    // Inherited via Character

    /// <summary>
    /// Reduces the damage taken by the defense amount. 
    /// If the player has a shield equipped, the damage is reduced even more by
    /// the shield boost.
    /// </summary>
    /// <param name="damage">The damage to deal to the player.</param>
    /// <returns>The total damage the player took.</returns>
    virtual float takeDamage(float damage) override;

    /// <summary>
    /// Calls the takeDamage function for the given character and passes in the player's damage value.
    /// If the player has a weapon equipped, the damage is raised by the stat boost.
    /// </summary>
    /// <param name="other">The character to attack.</param>
    /// <returns>The total damage dealt.</returns>
    virtual float attack(Character* other) override;
    
    /// <returns>The player's base damage combined with the weapon stat boost.</returns>
    virtual float getDamage() override;
    
    /// <returns>The player's base defense combined with the shield stat boost.</returns>
    virtual float getDefense() override;

private:
    Item m_weapon;
    Item m_shield;
};

