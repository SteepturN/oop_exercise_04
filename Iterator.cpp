#include "List.h"
#include "ListEl.h"
#include "Iterator.h"
Iterator::Iterator()
    : list(NULL), el(NULL) {}
Iterator& Iterator::operator++() {
    el = &((*el)->next);
    return *this;
}
Iterator::Iterator(const List* list, ListEl** el)
    : list(list), el(el) {}
bool Iterator::operator!=(Iterator iter) {
    return ((list != iter.list) || (el != iter.el));
}
Iterator::Iterator(List* l)
    : list(l), el(l->begin().el) {}
Triangle& Iterator::operator*() {
    return (*(el))->t;
}
bool Iterator::operator==(Iterator iter) {
    return !(*this != iter);
}
