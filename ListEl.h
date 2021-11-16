#ifndef LISTEL_H_
#define LISTEL_H_
#include "Triangle.h"
class ListEl {
    public:
    ListEl(ListEl* next, Triangle& t);
    ListEl(ListEl* next, Triangle&& t);
    ListEl* next;
    Triangle t;
};
#endif // LISTEL_H_
