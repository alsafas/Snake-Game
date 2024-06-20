#ifndef OBJPOS_H 
#define OBJPOS_H

class objPos
{
    public:

        // Data members
        int x;
        int y;
        char symbol;

        // Constructors
        objPos();
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);

        // Setters and Getters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos);
        char getSymbol();

        // Methods
        bool isPosEqual(const objPos* refPos);
        char getSymbolIfPosEqual(const objPos* refPos);
};

#endif