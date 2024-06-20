#include "Player.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef, snakeFood* myfood)
{
    mainGameMechsRef = thisGMRef;
    dir = STOP;
    myfoodclass = myfood;

    // more actions to be included
    objPos temp(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); //use getboardsize functions
                                                                                    //to place the player in the middle at startup 
    playerPosList = new objPosArrayList();

    playerPosList->insertHead(temp);        //create the snake head

}
 
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}
 
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos array list 
    return playerPosList;
}
 
void Player::updatePlayerDir()          //set the direction of the player based on keyboard input
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
 
void Player::movePlayer() 
{
    bool collision = false;             //track if player got food
    bool specialflag = false;           //track if food collected was special or normal 
    objPos temp;
    objPos foodtemp;
    objPos tailtemp;
    playerPosList->getHeadElement(temp);
   
    playerPosList->getTailElement(tailtemp);

    // PPA3 Finite State Machine logic (works mostly the same for each direction)
    if(dir == UP)
    {
        if(temp.y <= 1)                                  //wraparound logic 
        {
            temp.y = mainGameMechsRef->getBoardSizeY() - 1; 
        }
        temp.y--;                                              
        playerPosList->insertHead(temp);                    //makes snake appear to move forward
        myfoodclass->getFoodPos(foodtemp, 0);               //get the position of the superfood 
        if(temp.x == foodtemp.x && temp.y == foodtemp.y)     //check if player got super food
            {
                myfoodclass->clearFoodPos();                    //change the food positions 
                myfoodclass->generateFood(playerPosList);
                collision = true;                           
                specialflag = true;
            }
        for(int i = 1; i < 5; i++)                          //check if player got any normal food 
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
        if(collision == false || specialflag == true)       //if we dont want the snake to grow, remove the tail
        {
            playerPosList->removeTail();
        }
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   //check if snake collided with itself 
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    else if(dir == DOWN)                                                // repeat for other directions vv
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
        if ( temp.x == tailtemp.x && temp.y == tailtemp.y)   
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    if (collision == true)          //if food was collected, increment the score by different amounts depending
    {                                                          // on whether it was special or not 
        mainGameMechsRef->incrementScore(specialflag);
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
        if (temp.x == temp2.x && temp.y == temp2.y)   //check each body element position against the head pos
        {
            return true;                               //if pos are the same, report that collision occured
        }
    }
    return false;
}