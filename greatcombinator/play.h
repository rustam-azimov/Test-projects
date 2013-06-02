#ifndef PLAY_H
#define PLAY_H

#include "node.h"


void startTheGame();

int startFirstTour(); // the player make a riddle.

int startSecondTour(); // the computer make a riddle.

Node* getFirstTry(Node *head);

void removeInvalidValues(Node* head, Node* myProbe,
                         int numberOfExactMatches, int numberOfMatchByValue);

int getNumbOfExactMatches(Node* myProbe, Node* test);

int getNumbOfMatchByValue(Node* myProbe, Node* test);

#endif // PLAY_H
