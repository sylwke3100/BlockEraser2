#ifndef POSITION_H
#define POSITION_H

namespace BlockEngine{
    struct Position {
        Position(int stX, int soX, int StY, int SoY): startX(stX), startY(StY), stopX(soX), stopY(SoY) {}
        int startX;
        int startY;
        int stopX;
        int stopY;
    };
}
#endif // POSITION_H
