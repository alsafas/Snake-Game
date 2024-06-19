#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "snakeFood.h"

using namespace std;

#define DELAY_CONST 100000


GameMechs* gameM;
Player* myPlayer;
objPosArrayList* myPlayerPosList;

snakeFood* food;
objPos foodPos;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int speed;

int main(void)
{

    Initialize();

    while(gameM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gameM = new GameMechs();
    
    food = new snakeFood();

    myPlayer = new Player(gameM, food);
    myPlayerPosList = myPlayer->getPlayerPos();

    food->generateFood(myPlayerPosList);

    speed = 1;
    
}

void GetInput(void)
{
   //gameM->setInput(gameM->getInput());
}

void RunLogic(void)
{   
    /* if (myPlayer->getenumdirection() != 0) // Generate food after player has moved
    {
        food->generateFood(myPlayerPosList);
    } */ // the food should be displayed before the player moves

    switch(gameM->getInput())
    {                      
        case 27:  // Escape to exit
            gameM->setExitTrue();
            break;
        case '1':
            speed = 1;
            break;
        case '2':
            speed = 2;
           break;
        case '3':
            speed = 3;
            break;
        case '4':   
            speed = 4;
            break;
        case '5':
            speed = 5;
            break;
        case '0': //testing lose flag
            gameM->setLoseFlag();
            break;
        // case '=': //testing score increment
        //     gameM->incrementScore();
        //     break;
        /* case 'o': //testing food generation
            food->clearFoodPos();
            food->generateFood(myPlayerPosList);
            break; */
        default:
            break;
    }

    if (gameM->getLoseFlagStatus() == true)
    {
        gameM->setExitTrue();
    } 

       //run update player direction
    myPlayer->updatePlayerDir();
 
    //run move player
    myPlayer->movePlayer();
 
    //update the player position object for printing 
    //myPlayer->getPlayerPos(playerPosition);

    if (myPlayer->checkSelfCollision() == true)
    {
        gameM->setLoseFlag();
        gameM->setExitTrue();
    }

    gameM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos tempfood;
    objPos temp;
    bool printspace = true;

    //food->getFoodPos(foodPos);

    //Game board
    MacUILib_printf("Press ESC to exit\n");   

    MacUILib_printf("\n"); 
    for (int i = 0; i <= (gameM->getBoardSizeY() - 1); i++)
    {  
        for(int j = 0; j <= (gameM->getBoardSizeX() -1); j++)
        { 
            if(j == 0 || j == (gameM->getBoardSizeX() - 1) || i == 0 || i == (gameM->getBoardSizeY()-1))
            {
                MacUILib_printf("#");
                printspace = false;
            }
            else //if(j == foodPos.x && i == foodPos.y)
            {
                //MacUILib_printf("%c", foodPos.symbol);
                //printspace = false;
                for(int l = 0; l < 5; l++)
                {
                    food->getFoodPos(tempfood, l);
                    if(tempfood.x == j && tempfood.y == i)
                    {
                        MacUILib_printf("%c", tempfood.symbol);
                        printspace = false;
                        break;
                    }
                }
            }
            if(printspace == true)
            {
                for(int k = 0; k < myPlayerPosList->getSize(); k++)
                {
                    myPlayerPosList->getElement(temp, k);
                    if(temp.x == j && temp.y == i)
                    {
                        MacUILib_printf("%c", temp.symbol);
                        printspace = false;
                        break;
                    }
                }
            }
            if(printspace == true)
            {
                MacUILib_printf(" ");
            }
            printspace = true;
        }
        MacUILib_printf("\n");
    }
 
    MacUILib_printf("\n");

    //Game info + Testing functions

    MacUILib_printf("Press 1-5 to change speed\n");
    MacUILib_printf("1: Slowest  2: Slow  3: Normal  4: Fast  5: Fastest\n");
    MacUILib_printf("Score: %d\n", gameM->getScore());
    MacUILib_printf("Press 0 to test lose flag\n");
    // MacUILib_printf("Press = to test score increment\n");

    MacUILib_printf("the direction is: %d", myPlayer->getenumdirection());
}

void LoopDelay(void)
{
    switch(speed){

        case 1:
            MacUILib_Delay(DELAY_CONST*5);
            break;
        case 2:
            MacUILib_Delay(DELAY_CONST*4);
            break;
        case 3:
            MacUILib_Delay(DELAY_CONST*3);
            break;
        case 4:
            MacUILib_Delay(DELAY_CONST*2);
            break;
        case 5:
            MacUILib_Delay(DELAY_CONST);
            break;
        default:
            MacUILib_Delay(DELAY_CONST);
            break;
    }

}


void CleanUp(void)
{
    MacUILib_clearScreen();   
        if (gameM->getLoseFlagStatus() == true){
        MacUILib_printf("\nGame Over!\n\n");
    }
    MacUILib_printf("Final score: %d\n", gameM->getScore());

    delete gameM;
    delete myPlayer;
    delete food;
    MacUILib_uninit();
}
