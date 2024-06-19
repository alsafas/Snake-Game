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
    foodBucket = new objPosArrayList(); 
    numofFood = 5;
    count = 0;
    i, j, x, y;
    boardX = getBoardSizeX(); 
    boardY = getBoardSizeY();
    
}

snakeFood::~snakeFood()
{
    delete foodBucket;
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
    bool ontopflag = false;     //tracking if food lands on player, other food, border
    int vector[30][15] = {0};      //bit vector method for random generation
 
    srand(time(NULL)); // Seed the random number generator with the current time
   
    for(i = 0; i < boardX; i++)     //bit vector method setup 
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
 
    while(count < numofFood-1)      //get 4 regular food in random non-overlapping positions on the board 
    {
        x = rand() % (boardX -1);
        y = rand() % (boardY -1);
 
        objPos temp;
        objPos tempFoodPos;
        tempFoodPos.setObjPos(x, y, 'o');
 
        if(vector[x][y] == 0)
        {
           for(int k = 0; k < accessarray->getSize(); k++)      //check position against snake 
            {
                accessarray->getElement(temp, k);
                if(tempFoodPos.isPosEqual(&temp) == true)
                {
                    ontopflag = true;
                    break;
                }
            }  
            for(int j = 0; j < foodBucket->getSize(); j++)      //check postion against other food 
            {
                foodBucket->getElement(temp, j);
                if(tempFoodPos.isPosEqual(&temp) == true)
                {
                    ontopflag = true;
                    break;
                }
            }
         
        if(ontopflag == false)      //if the position is empty, mark it full, and add food in that position 
        {
            vector[x][y]++;
            foodBucket->insertHead(tempFoodPos);
            count++;
        }
        }
        ontopflag = false;
    }
    while(count < numofFood)        //generate one special food in the same manor as above but with ? symbol
    {
         x = rand() % (boardX -1);
        y = rand() % (boardY -1);
 
        objPos temp;
        objPos tempFoodPos;
        tempFoodPos.setObjPos(x, y, '?');
 
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
            for(int j = 0; j < foodBucket->getSize(); j++)
            {
                foodBucket->getElement(temp, j);
                if(tempFoodPos.isPosEqual(&temp) == true)
                {
                    ontopflag = true;
                    break;
                }
            }
         
        if(ontopflag == false)
        {
            vector[x][y]++;
            //foodPos.setObjPos(x, y, 'o');
            foodBucket->insertHead(tempFoodPos);
            count++;
        }
        }
        ontopflag = false;
    }
 
}

void snakeFood::getFoodPos(objPos &returnPos, int index)
{
    foodBucket->getElement(returnPos, index);
}

void snakeFood::clearFoodPos()
{
    count = 0;
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        foodBucket->removeTail();
    }
}