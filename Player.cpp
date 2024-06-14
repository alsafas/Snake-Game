#include "Player.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    dir = STOP;
 
    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); //use getboardsize functions
 
    //no heap members yet
}
 
Player::~Player()
{
    // delete any heap members here
   
}
 
void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list (ignoring this for now)
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}
 
void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
     switch(input)
        {                      
 
            case 'w':
                if(dir == LEFT || dir == RIGHT || dir == STOP)
                {
                    dir = UP;
                }
                break;
            case 'a':
                if(dir == DOWN || dir == UP || dir == STOP)
                {
                    dir = LEFT;
                }
                break;
            case 's':
                if(dir == LEFT || dir == RIGHT || dir == STOP)
                {
                    dir = DOWN;
                }
                break;
            case 'd':
                if(dir == UP || dir == DOWN || dir == STOP)
                {  
                    dir = RIGHT;
                }
                break;
            default:
                break;
        }
 
    // PPA3 input processing logic      
}
 
void Player::movePlayer() //change everything to use game board
{
    // PPA3 Finite State Machine logic
    if(dir == UP)
    {
        if(playerPos.y <= 1)
        {
            playerPos.y = mainGameMechsRef->getBoardSizeY() - 1; 
        }
        playerPos.y--;
    }
    else if(dir == DOWN)
    {
        if(playerPos.y >= mainGameMechsRef->getBoardSizeY() - 2) 
        {
            playerPos.y = 0;
        }
        playerPos.y++;
    }
    else if(dir == LEFT)
    {
        if(playerPos.x <= 1)
        {
            playerPos.x = mainGameMechsRef->getBoardSizeX() - 1; 
        }
        playerPos.x--;
    }
    else if(dir == RIGHT)
    {
        if(playerPos.x >= mainGameMechsRef->getBoardSizeX() -2) 
        {
            playerPos.x = 0;
        }
        playerPos.x++;
    }
    else
    {

    }
}

Player::Dir Player::getenumdirection()
{
    return dir;
}
 
 