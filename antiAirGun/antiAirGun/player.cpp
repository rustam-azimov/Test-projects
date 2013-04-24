#include "player.h"

Player::Player() :
    score(0),
    scoreForPlane(50),
    healthPoints(5),
    damageFromPlane(1)
{
}

void Player::addScoreForPlane()
{
    score += scoreForPlane;
    if (score > 9999)
        score = 9999;
    emit scoreChanged(score);
}

void Player::reduceHpFromPlane()
{
    healthPoints--;
    if (healthPoints < 0)
        healthPoints = 0;
    emit hpChanged(healthPoints);
}
