#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

//bool exitFlag;

GameMechs* gameM;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int i, j;

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

}

void GetInput(void)
{
   gameM->setInput(gameM->getInput());
}

void RunLogic(void)
{

    switch(gameM->getInput())
    {                      
        case 27:  // Escape to exit
            gameM->setExitTrue();
            break;
    }
    gameM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("Press ESC to exit\n");   
    for (i=0; i<=gameM->getBoardSizeX(); i++){  
        MacUILib_printf("#");
    }
    MacUILib_printf("\n"); 
    for (i=0; i<= (gameM->getBoardSizeY() - 1); i++){  
        
        for(j=0; j<=gameM->getBoardSizeX(); j++){ 
            if(j == 0 || j == gameM->getBoardSizeX()){
                MacUILib_printf("#");
            }
            // else if (player.x == j && player.y == i){
            //     MacUILib_printf("%c", player.symbol);
            // }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    for (i=0; i<=gameM->getBoardSizeX(); i++){  
        MacUILib_printf("#");
    }
    MacUILib_printf("\n"); 

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete[] gameM;
    MacUILib_uninit();
}
