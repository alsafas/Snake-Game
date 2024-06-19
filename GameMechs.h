#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;



class GameMechs
{   

    //all variables and methods created based on UML diagram 

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        
        int score;
        int boardSizeX;
        int boardSizeY;

    public:

        //constructors
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();

        //getters
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();


        //setters
        void setExitTrue();
        void setLoseFlag();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();
        
};

#endif