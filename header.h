#ifndef HEADER_H
#define HEADER_H
#include <iostream>
struct RGBColor{
    int first  = 0;
    int second = 0;
    int third  = 0;
    RGBColor() = default;
    RGBColor(int one,
             int two,
             int thirth): first(one), second(two), third(thirth){}
    bool operator == (RGBColor Color) {
        if (this->first == Color.first && this->second == Color.second && this->third == Color.third)
            return true;
        else
            return false;
    }
    operator bool() const {
        if (this->first == 0 && this->second == 0 && this->third == 0)
            return false;
        else
            return true;
    }

    void set(int one, int two, int thirth){
        first = one;
        second = two;
        third = thirth;
    }
};



#endif // HEADER_H
