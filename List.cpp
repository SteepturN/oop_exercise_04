#include "Triangle.h"
#include "List.h"
#include "ListEl.h"
#include "Iterator.h"

List::List()
    : head(NULL), size(0), tail(NULL) {}
List::~List() {
    /*for(auto cur = this->begin(); cur != this->end();) {
        auto del = cur; //Error because when I ++cur I still need to use
        //pointer to the next ListEL which is contained in
        //del, and pointer-attribute of cur points to del's attribute
        ++cur;
        std::cout << (*(del.el))->t;
        delete(*(del.el));
    }*/
    for(auto cur = head; cur != NULL;) {
        auto del = cur;
        cur=cur->next;
        delete(del);
    }
}
int List::put(Triangle& t, Iterator i) { //inserts before
    ListEl* new_list_element = new ListEl(*(i.el), t);
    *(i.el) = new_list_element;
    ++size;
    if(new_list_element->next == NULL)
        tail = &(new_list_element->next);
    return 0;
}
void List::remove(Iterator i) {
    auto del_this = *(i.el);
    *(i.el) = (*(i.el))->next;
    if(*(i.el) == NULL)
        tail = i.el;
    --size;
    delete(del_this);
}
Triangle& List::get(Iterator i) {
    return *i;
}
Iterator List::begin() {
    return Iterator(this, &head);
}
Iterator List::end() {
    return Iterator(this, tail);
}
std::ostream& operator<<(std::ostream& cout, List& list) {
    for(auto i = list.begin(); i != list.end(); ++i) {
        cout << *i << '\n';
    }
    return cout;
}
