#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000


GameMechs* gameM;
Player* myPlayer;
objPos playerPosition;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int i, j, speed;

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
    myPlayer = new Player(gameM);
    speed = 1;

    myPlayer->getPlayerPos(playerPosition);
}

void GetInput(void)
{
   //gameM->setInput(gameM->getInput());
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
        case '0': //testing lose flag
            gameM->setLoseFlag();
            break;
        case '=': //testing score increment
            gameM->incrementScore();
            break;
        default:
            break;
    }
    //gameM->clearInput();

    if (gameM->getLoseFlagStatus() == true){
        gameM->setExitTrue();
    } 

       //run update player direction
    myPlayer->updatePlayerDir();
 
    //run move player
    myPlayer->movePlayer();
 
    //update the player position object for printing 
    myPlayer->getPlayerPos(playerPosition);
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    //Game board
    MacUILib_printf("Press ESC to exit\n");   

    MacUILib_printf("\n"); 
    for (i = 0; i <= (gameM->getBoardSizeY() - 1); i++)
    {  
        
        for(j = 0; j <= (gameM->getBoardSizeX() -1); j++)
        { 
            if(j == 0 || j == gameM->getBoardSizeX()-1 || i == 0 || i == gameM->getBoardSizeY()-1)
            {
                MacUILib_printf("#");
            }
            else if(j == playerPosition.x && i == playerPosition.y)
            {
                MacUILib_printf("%c", playerPosition.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
 
    MacUILib_printf("\n");

    //Game info + Testing functions

    MacUILib_printf("Press 1-5 to change speed\n");
    MacUILib_printf("1: Slowest  2: Slow  3: Normal  4: Fast  5: Fastest\n");
    MacUILib_printf("Score: %d\n", gameM->getScore());
    MacUILib_printf("Press 0 to test lose flag\n");
    MacUILib_printf("Press = to test score increment\n");

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
    MacUILib_uninit();
}
