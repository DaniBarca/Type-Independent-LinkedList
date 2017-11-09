#include <iostream>
#include "header/LinkedList.hpp"

class Test1 : public LNode {
public:
    float data1;
    float data2;
    float data3;

    Test1(float d1, float d2, float d3){
        data1 = d1;
        data2 = d2;
        data3 = d3;
    }

    std::string ToString(){
        return std::to_string(data1) + " " + std::to_string(data2) + " " + std::to_string(data3);
    }

    ~Test1(){}
};

class Test2 : public LNode {
public:
    int data1;
    float data2;

    Test2(int d1, float d2){
        data1 = d1;
        data2 = d2;
    }

    std::string ToString(){
        return std::to_string(data1) + " " + std::to_string(data2);
    }

    ~Test2(){}
};

class Test3 : public LNode {
public:
    std::string data1;
    std::string data2;

    Test3(std::string d1, std::string d2){
        data1 = d1;
        data2 = d2;
    }

    std::string ToString(){
        return data1 + " " + data2;
    }

    ~Test3(){}
};

int main(){
    LinkedList l;
    
    l.Add((LNode*)new Test1(0.5f, 0.3f, 0.9f));
    l.Add((LNode*)new Test2(1, 0.1f));
    l.Insert((LNode*)new Test3("a", "test"), 1);
    l.Insert((LNode*)new Test3("b", "test"), 1);
    l.Insert((LNode*)new Test3("c", "test"), 0);

    for(LNode* i = l.First(); i != NULL; i = i->Next()){
        std::cout << i->ToString() << std::endl;
    }
}
