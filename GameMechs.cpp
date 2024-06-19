#include "GameMechs.h"
#include "MacUILib.h"
 
#include "objPos.h"
#include "objPosArrayList.h"
 
 
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    
    score = 0;
    boardSizeX = 30;   //Default board size
    boardSizeY = 15;
}
 
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
 
    score = 0;
    boardSizeX = boardX;  
    boardSizeY = boardY;
}
 
// do you need a destructor?
GameMechs::~GameMechs()   //nothin allocated on heap in the constructor 
{
    
}
 
 
//Getters
 
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}
 
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}
 
char GameMechs::getInput()
{
    if (MacUILib_hasChar() != 0){
        input = MacUILib_getChar();
    }
    return input;
}
 
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}
 
int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}
 
int GameMechs::getScore()
{
    return score;
}
 
//Setters
 
void GameMechs::setExitTrue()
{
    exitFlag = true;
}
 
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
 
void GameMechs::setInput(char this_input)
{
    input = this_input;
}
 
void GameMechs::clearInput()
{
    input = 0;
}
 
void GameMechs::incrementScore(bool flag)       //flag true means a special food was eaten
{
    if(flag == true)                    
    {
        score += 5;
    }
    else
    {
        score += 1;
    }
  
}
