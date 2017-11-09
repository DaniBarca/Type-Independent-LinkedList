#include "LinkedList.hpp"

LinkedList* LinkedList::Node::List(){
    return _list;
}

LinkedList::Node* LinkedList::Node::Prev(){
    return _prev;
}

LinkedList::Node* LinkedList::Node::Next(){
    return _next;
}

LinkedList::Node::~Node(){
    _list = NULL;
}