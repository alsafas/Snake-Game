#include "Player.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef, snakeFood* myfood)
{
    mainGameMechsRef = thisGMRef;
    dir = STOP;
    myfoodclass = myfood;

    //scoreflag = 1;
 
    // more actions to be included
    objPos temp(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); //use getboardsize functions
 
    playerPosList = new objPosArrayList();
    //no heap members yet
    playerPosList->insertHead(temp);

}
 
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}
 
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos array list (ignoring this for now)
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);

    return playerPosList;
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
    bool collision = false;
    bool specialflag = false;
    objPos temp;
    objPos foodtemp;
    objPos tailtemp;
    playerPosList->getHeadElement(temp);
    //myfoodclass->getFoodPos(foodtemp);
    playerPosList->getTailElement(tailtemp);

    // PPA3 Finite State Machine logic
    if(dir == UP)
    {
        if(temp.y <= 1)
        {
            temp.y = mainGameMechsRef->getBoardSizeY() - 1; 
        }
        temp.y--;
        playerPosList->insertHead(temp);
        myfoodclass->getFoodPos(foodtemp, 0);
        if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                specialflag = true;
            }
        for(int i = 1; i < 5; i++)
        {
            myfoodclass->getFoodPos(foodtemp, i);
            if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                break;
            }
        }
        if(collision == false || specialflag == true)
        {
            playerPosList->removeTail();
        }

      /*   if(temp.x == foodtemp.x && temp.y == foodtemp.y)
        {
            myfoodclass->clearFoodPos();
            myfoodclass->generateFood(playerPosList);
        }
        else
        {
            playerPosList->removeTail();
        } */
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }

       
    }
    else if(dir == DOWN)
    {
        if(temp.y >= mainGameMechsRef->getBoardSizeY() - 2) 
        {
            temp.y = 0;
        }
        temp.y++;
        playerPosList->insertHead(temp);
        myfoodclass->getFoodPos(foodtemp, 0);
        if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                specialflag = true;
            }
        for(int i = 1; i < 5; i++)
        {
            myfoodclass->getFoodPos(foodtemp, i);
            if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                break;
            }
        }
        if(collision == false || specialflag == true)
        {
            playerPosList->removeTail();
        }
        // if(temp.x == foodtemp.x && temp.y == foodtemp.y)
        // {
        //     myfoodclass->clearFoodPos();
        //     myfoodclass->generateFood(playerPosList);
        // }
        // else
        // {
        //     playerPosList->removeTail();
        // }
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
   
    }
    else if(dir == LEFT)
    {
        if(temp.x <= 1)
        {
            temp.x = mainGameMechsRef->getBoardSizeX() - 1; 
        }
        temp.x--;
        playerPosList->insertHead(temp);
        myfoodclass->getFoodPos(foodtemp, 0);
        if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                specialflag = true;
            }
        for(int i = 1; i < 5; i++)
        {
            myfoodclass->getFoodPos(foodtemp, i);
            if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                break;
            }
        }
        if(collision == false || specialflag == true)
        {
            playerPosList->removeTail();
        }
      /*   if(temp.x == foodtemp.x && temp.y == foodtemp.y)
        {
            myfoodclass->clearFoodPos();
            myfoodclass->generateFood(playerPosList);
        }
        else
        {
            playerPosList->removeTail();
        } */
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }
    else if(dir == RIGHT)
    {
        if(temp.x >= mainGameMechsRef->getBoardSizeX() -2) 
        {
            temp.x = 0;
        }
        temp.x++;
        playerPosList->insertHead(temp);
        myfoodclass->getFoodPos(foodtemp, 0);
        if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                specialflag = true;
            }
        for(int i = 1; i < 5; i++)
        {
            myfoodclass->getFoodPos(foodtemp, i);
            if(temp.x == foodtemp.x && temp.y == foodtemp.y)
            {
                myfoodclass->clearFoodPos();
                myfoodclass->generateFood(playerPosList);
                collision = true;
                break;
            }
        }
        if(collision == false || specialflag == true)
        {
            playerPosList->removeTail();
        }
    /*     if(temp.x == foodtemp.x && temp.y == foodtemp.y)
        {
            myfoodclass->clearFoodPos();
            myfoodclass->generateFood(playerPosList);
        }
        else
        {
            playerPosList->removeTail();
        } */
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }


    if (collision == true)
    {
        mainGameMechsRef->incrementScore(specialflag);
        //scoreflag++;
    }
 
}

Player::Dir Player::getenumdirection()
{
    return dir;
}
 
 
bool Player::checkSelfCollision()
{
    objPos temp;
    playerPosList->getHeadElement(temp);
    objPos temp2;
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(temp2, i);
        if (temp.x == temp2.x && temp.y == temp2.y)
        {
            return true;
        }
    }
    return false;
}