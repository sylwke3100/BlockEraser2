#ifndef POSITION_H
#define POSITION_H

struct Position {
    Position(int stX, int soX, int StY, int SoY): startX(stX), stopX(soX), stopY(SoY), startY(StY){}
    int startX;
    int startY;
    int stopX;
    int stopY;
};

#endif // POSITION_H
