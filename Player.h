#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h" 
#include "snakeFood.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {STOP, UP, DOWN, LEFT, RIGHT};  // This is the direction state (FSM)

        Player(GameMechs* thisGMRef, snakeFood* myfood);
        ~Player();

        objPosArrayList* getPlayerPos(); 
        void updatePlayerDir();
        void movePlayer();

        bool checkSelfCollision();
        Player::Dir getenumdirection();
    private:
        objPosArrayList* playerPosList;          
        enum Dir dir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        //reference to food class
        snakeFood* myfoodclass;
};

#endif