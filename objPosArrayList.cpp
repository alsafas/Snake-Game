#include "objPosArrayList.h" 

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeArray = ARRAY_MAX_CAP;              //holds the size of the array 
    sizeList = 0;                       //holds the size of the list within the array, the useful info
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList != sizeArray)                       //as long as the array isn't full, elements can be added to                                           
    {                                               //the string
        for(int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);         //must shuffle all the elements towards the tail 
        }
        aList[0].setObjPos(thisPos);                //insert element at head
        sizeList++;                                 //increase the size of the list when adding useful info 
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList != sizeArray)                       //as long as the array isn't full, elements can be added to
    {                                               //the string
        aList[sizeList].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::removeHead()
{
    if(sizeList > 0)                                //if the snake exists, shuffle the items towards the head
    {
        for(int i = 0; i < (sizeList -1); i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if(sizeList > 1)
    {
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}