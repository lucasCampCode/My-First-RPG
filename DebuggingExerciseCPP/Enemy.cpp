#include <time.h>
#include <stdlib.h>
#include "Enemy.h"

float Enemy::attack(Character* other)
{
    /* initialize random seed: */
    srand(time(NULL));
    /* generate secret number between 1 and 10: */
    float randomDamage = rand() % 10 + 1;

    return other->takeDamage(getDamage() + randomDamage);
}
