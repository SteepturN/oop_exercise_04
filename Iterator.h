#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "ListEl.h"
#include "List.h"
#include "Triangle.h"
class Iterator {
public:
    const List* list;
    ListEl** el;
    Iterator();
    Iterator(List*);
    Iterator(const List*, ListEl**);
    Iterator& operator++();
    Triangle& operator*();
    bool operator!=(Iterator iter);
    bool operator==(Iterator);
};

#endif // ITERATOR_H_
