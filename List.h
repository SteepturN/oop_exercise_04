#ifndef LIST_H
#define LIST_H
#include "ListEl.h"
#include "Triangle.h"
class Iterator;
class List {
public:
    List();
    ~List();
    Iterator begin();
    int put(Triangle& t);
    int put(Triangle& t, Iterator i);
    Triangle& get(Iterator p);
    void remove(Iterator p);
    Iterator end();
	friend std::ostream& operator<<(std::ostream&, List&);
    ListEl* head;
    unsigned int size;
    ListEl** tail;
};
#endif // LIST_H
