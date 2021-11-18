#include "Triangle.h"
#include "List.h"
#include "ListEl.h"
#include "Iterator.h"

List::List()
    : head(new ListEl(NULL, Triangle())), size(0) {}
List::~List() {
    for(auto cur = this->begin(); cur != this->end();) {
        auto del = cur;
        ++cur;
        delete(*(del.el));
    }
    delete(head);
}
int List::put(Triangle& t, Iterator i) {
    ListEl* new_list_element = new ListEl((*(i.el))->next, t);
    *(i.el) = new_list_element;
    ++size;
    return 0;
}
void List::remove(Iterator i) {
    auto del_this = i;
    *(i.el) = ((*(i.el))->next);
    delete(*(del_this.el));
    --size;
}
Triangle& List::get(Iterator i) {
    return *i;
}
Iterator List::begin() {
    return Iterator(this, &(head->next));
}
Iterator List::end() {
    return Iterator(this, NULL);
}
std::ostream& operator<<(std::ostream& cout, List& list) {
    for(auto i = list.begin(); i != list.end(); ++i) {
        cout << *i;
    }
    return cout;
}
