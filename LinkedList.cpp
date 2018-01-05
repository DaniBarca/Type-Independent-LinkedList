#include "LinkedList.hpp"
#include <assert.h>

LinkedList::LinkedList(){
    _first = NULL;
    _last = NULL;
    
    _count = 0;
}

LinkedList* LinkedList::Add(Node* node){
    return Insert(node, _count);
}

LinkedList* LinkedList::Insert(Node* node, unsigned int i){
    assert(i <= _count);

    node->_list = this;
    if(_count == 0){
        _first     = node;
        _last      = node;
        node->_prev = NULL;
        node->_next = NULL;

        _count++;
        return this;
    }

    if(i == 0){
        _first->_prev = node;
        node->_next   = _first;
        node->_prev   = NULL;
        _first        = node;

        _count++;
        return this;
    }

    if(i == _count){
        _last->_next = node;
        node->_prev  = _last;
        node->_next  = NULL;
        _last        = node;

        _count++;
        return this;
    }

    Node* newNext = Get(i);
    Node* newPrev = newNext->_prev;
    
    node->_next = newNext;
    node->_prev = newPrev;

    newPrev->_next = node;
    newNext->_prev = node;

    _count++;
    return this;
}

LinkedList::Node* LinkedList::Get(unsigned int i){
    assert(_count > 0 && i < _count);
    Node* current = _first;
    for(unsigned int j = 1; j <= i; ++j){
        assert(current->_next != NULL);
        current = current->_next;
    }
    return current;
}

LinkedList::Node* LinkedList::Remove(unsigned int i){
    assert(_count > 0 && i < _count);
    
    Node* toRemove = Get(i);
    Node* prev     = toRemove->_prev;
    Node* next     = toRemove->_next;

    if(prev != NULL)
        prev->_next = next;
    
    if(next != NULL)
        next->_prev = prev;

    toRemove->_next = NULL;
    toRemove->_prev = NULL;

    if(_first == toRemove)
        _first = _count > 1 ? next : NULL;

    if(_last == toRemove)
        _last = _count > 1 ? prev : NULL;

    _count--;
    return toRemove;
}

void LinkedList::Delete(unsigned int i){
    delete Remove(i);
}

LinkedList::Node* LinkedList::First(){
    return _first;
}

LinkedList::Node* LinkedList::Last(){
    return _last;
}

unsigned int LinkedList::Count(){
    return _count;
}

LinkedList::~LinkedList(){
    if(_count == 0) return;
    
    Node* current = _first;
    for(unsigned int i = 0; i < _count - 1; ++i){
        current = current->Next();
        delete current->_prev;
    }
    delete current;
}
