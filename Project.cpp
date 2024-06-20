#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "snakeFood.h"

using namespace std;

#define DELAY_CONST 100000

// Global variables
GameMechs* gameM;
Player* myPlayer;
objPosArrayList* myPlayerPosList;
snakeFood* food;
objPos foodPos;
// extra feature: control how fast the game appears to move
int speed;       

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
 

int main(void)
{

    Initialize();

    // Main game loop
    while(gameM->getExitFlagStatus() == false)  //while the exit flag is false keep running the game
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

    //initialize the game on the heap
    gameM = new GameMechs();
    food = new snakeFood();
    myPlayer = new Player(gameM, food);

    // Set the initial positions
    myPlayerPosList = myPlayer->getPlayerPos();
    food->generateFood(myPlayerPosList);
    speed = 1;
    
}

void GetInput(void)
{
   //no input is needed here as it is grabbed in runlogic funtions 
}

void RunLogic(void)
{
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
        default:
            break;
    }

    if(gameM->getLoseFlagStatus() == true)
    {
        gameM->setExitTrue();                   //exit without losing the game
    } 

    //run update player direction
    myPlayer->updatePlayerDir();
 
    //run move player
    myPlayer->movePlayer();

    if (myPlayer->checkSelfCollision() == true)     //exit by snake death
    {
        gameM->setLoseFlag();
        gameM->setExitTrue();
    }

    gameM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Variables for location of food and snake
    objPos tempfood;
    objPos temp;

    bool printspace = true;

    //Print out the Game Board, the Snake, and the Food
    MacUILib_printf("Press ESC to exit\n");   

    MacUILib_printf("\n"); 
    for (int i = 0; i <= (gameM->getBoardSizeY() - 1); i++)  //loop through the board
    {  
        for(int j = 0; j <= (gameM->getBoardSizeX() -1); j++) 
        { 
            if(j == 0 || j == (gameM->getBoardSizeX() - 1) || i == 0 || i == (gameM->getBoardSizeY()-1)) //check if the current position is a border
            {
                MacUILib_printf("#");  //print the border
                printspace = false;
            }
            else 
            {
                for(int l = 0; l < 5; l++) //loop through the food
                {
                    food->getFoodPos(tempfood, l);  //get the food position
                    if(tempfood.x == j && tempfood.y == i) //check if the food is at the current position
                    {
                        MacUILib_printf("%c", tempfood.symbol); //print the food
                        printspace = false;
                        break;
                    }
                }
            }
            if(printspace == true)
            {
                for(int k = 0; k < myPlayerPosList->getSize(); k++) //loop through the snake
                {
                    myPlayerPosList->getElement(temp, k); // get the snake position
                    if(temp.x == j && temp.y == i) // check if the snake is at the current position
                    {
                        MacUILib_printf("%c", temp.symbol); // print the snake
                        printspace = false;
                        break;
                    }
                }
            }
            if(printspace == true)
            {
                MacUILib_printf(" "); //print a space
            }
            printspace = true;
        }
        MacUILib_printf("\n");
    }
 
    MacUILib_printf("\n");

    //Game info display

    MacUILib_printf("Press 1-5 to change speed\n");
    MacUILib_printf("1: Slowest  2: Slow  3: Normal  4: Fast  5: Fastest\n");
    MacUILib_printf("Current Speed: %d\n", speed);
    MacUILib_printf("Score: %d\n", gameM->getScore());
}

void LoopDelay(void)
{
    //delay the game based on the speed selected
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
        default: //default speed 
            MacUILib_Delay(DELAY_CONST);
            break;
    }

}


void CleanUp(void)
{
    MacUILib_clearScreen();   
    if (gameM->getLoseFlagStatus() == true)     //print a message depending on how the game finished 
    {
        MacUILib_printf("\nYou Lost\n");
    }
    else
    {   
        MacUILib_printf("You Quit the Game");
    }
    MacUILib_printf("\nGame Over!\n\n");

    // Print the final score
    MacUILib_printf("Final score: %d\n", gameM->getScore());

    // Clean up heap memory
    delete gameM;
    delete myPlayer;
    delete food;

    MacUILib_uninit();
}
