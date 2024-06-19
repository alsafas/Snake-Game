#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H
 
#define ARRAY_MAX_CAP 364           //this is the maximum value of spaces the snake could occupy on 
                                    //our game board

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList;
        int sizeArray;

    public:
        objPosArrayList();
        ~objPosArrayList();

        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        int getSize();
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif