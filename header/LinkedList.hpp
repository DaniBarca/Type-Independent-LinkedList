#include <stdio.h>
#include <string>

class LinkedList{
public:
    class Node {
        friend class LinkedList;
    private:
        LinkedList* _list;
        Node* _prev;
        Node* _next;

    public:
        LinkedList* List();
        Node* Prev();
        Node* Next();

        virtual std::string ToString() = 0;
        virtual ~Node();
    };

private:
    unsigned int _count;
    Node* _first;
    Node* _last;

public:
    LinkedList();

    LinkedList* Add(Node* node);
    LinkedList* Insert(Node* node, unsigned int position);

    Node* Get(unsigned int i);
    Node* Remove(unsigned int i);

    Node* First();
    Node* Last();

    unsigned int Count();

    ~LinkedList();
};

typedef LinkedList::Node LNode;
