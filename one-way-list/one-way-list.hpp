#ifndef _ONEWAYLIST_H_
#define _ONEWAYLIST_H

class Node
{
public:
    int data;
    Node *next;
};

class oneWayList
{
private:
    Node *HEAD;

public:
    oneWayList(); //ok
    ~oneWayList();    //ok
    int getLength();  //ok
    void creatOneWayList(int size);  //ok
    void printList();  //ok
    bool isEmpty();   //ok
    Node *find(int value);   //ok
    void insertOneElement(int value, int pos);  //ok
    void deleteOneElement(int value);   //??
    void deleteListAllNodes();    //ok
};

#endif //ONEWAYLIST_H