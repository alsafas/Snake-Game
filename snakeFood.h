#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include <cstdlib> //C++ standard library, rand(), srand()
#include <time.h>   //C++ <ctime>, time()
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;



class snakeFood : public GameMechs , public objPos 
{   

    //all variables and methods created based on UML diagram 

    private:
        objPos foodPos;
        int listSize;
        int count, i, j, boardX, boardY;
        int vector[30][15];
        int x, y;

    public:

        //constructors
        snakeFood();

        //destructors
        ~snakeFood();
        
        //getters
        void getFoodPos(objPos &returnPos);

        //methods
        void generateFood(objPosArrayList* accessarray);
        void clearFoodPos();
};

#endif