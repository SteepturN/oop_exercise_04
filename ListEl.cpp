#include "ListEl.h"
#include "Triangle.h"


ListEl::ListEl(ListEl* next, Triangle& t)
    : next(next), t(t) {}
ListEl::ListEl(ListEl* next, Triangle&& t)
    : next(next), t(t) {}
