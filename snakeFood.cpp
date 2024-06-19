#include "SnakeFood.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <time.h>

using namespace std;



snakeFood::snakeFood()
{
    foodPos.setObjPos(-1,-1, 'o'); //Initialize outside the game board
                                //so that food is not initially displayed
    listSize = 1;
    count = 0;
    i, j, x, y;
    boardX = getBoardSizeX(); 
    boardY = getBoardSizeY();
    
}

snakeFood::~snakeFood()
{

}

void snakeFood::generateFood(objPosArrayList* accessarray)
{
   
    //blockOff should contain player position
 
    //generate random x and y coordinates for your food item,
    // and make sure that they are NOT:
    // 1. on the border
    // 2. or clash with the player position (blockOff)
 
    // Check x and y against 0 and boardSizeX/boardSizeY to make sure they are not on the border
 
    // Check against the player position to make sure they are not on the player position
    // use isPosEqual() method instead of doing element-by-element comparison
 
    //and then set the food position using the setObjPos method of the objPos class with newly generated x and y coordinates
    bool ontopflag = false;
    int vector[30][15];
 
    srand(time(NULL)); // Seed the random number generator with the current time
   
    for(i = 0; i < boardX; i++)
    {
        for(j = 0; j < boardY; j++)
        {
            if(i == 0 || j == 0 || i == boardX-1 || j == boardY-1)
            {
                vector[i][j] = 1;
            }
            else
            {
                vector[i][j] = 0;
            }
        }
    }
 
    while(count < listSize)
    {
        x = rand() % (boardX -1);
        y = rand() % (boardY -1);
 
        objPos temp;
        objPos tempFoodPos;
 
        tempFoodPos.setObjPos(x, y, 'o');
 
        if(vector[x][y] == 0)
        {
           for(int k = 0; k < accessarray->getSize(); k++)
                {
                    accessarray->getElement(temp, k);
                    if(tempFoodPos.isPosEqual(&temp) == true)
                    {
                        ontopflag = true;
                        break;
                    }
                }  
         
        if(ontopflag == false)
        {
            vector[x][y]++;
            foodPos.setObjPos(x, y, 'o');
            count++;
        }
        }
        ontopflag = false;
    }
 
}

void snakeFood::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}

void snakeFood::clearFoodPos(){
    count = 0;
    foodPos.setObjPos(-1,-1, 'o');
}