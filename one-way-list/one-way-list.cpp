#include "one-way-list.hpp"
#include <iostream>

oneWayList::oneWayList()
{
    HEAD = new Node;
    HEAD->data = 0;
    HEAD->next = nullptr;
}

oneWayList::~oneWayList()
{
    deleteListAllNodes();
    delete HEAD;
}

int oneWayList::getLength()
{
    int size = 0;
    Node *p = HEAD->next;
    while (p != nullptr)
    {
        size++;
        p = p->next;
    }
    return size;
}

bool oneWayList::isEmpty()
{
    if (HEAD->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void oneWayList::creatOneWayList(int nums)
{
    if (nums < 0)
    {
        std::cout << "input nums error!" << std::endl;
        exit(-1);
    }
    Node *ptemp = HEAD;
    for (int i = 0; i < nums; i++)
    {
        Node *pnew = new Node;
        std::cout << "input " << i + 1 << " value" << std::endl;
        std::cin >> pnew->data;
        pnew->next = nullptr;
        ptemp->next = pnew;
        ptemp = pnew;
    }
}

void oneWayList::printList()
{
    if (isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        Node *p = HEAD;
        while (p->next != nullptr)
        {
            p = p->next;
            std::cout << p->data << std::endl;
        }
    }
}

Node *oneWayList::find(int value)
{
    if (isEmpty())
    {
        std::cout << "error : empty list" << std::endl;
        return nullptr;
    }
    else
    {
        Node *p = HEAD;
        do
        {
            p = p->next;
        } while ((value != p->data) && (p != nullptr)); //first found node
        if (p->data == value)
        {
            return p;
        }
        else
        {
            std::cout << "Not found!" << std::endl;
        }
    }
}

void oneWayList::insertOneElement(int value, int pos)
{
    if (pos < 0)
    {
        std::cout << "invalid input pos!" << std::endl;
    }
    Node *p = HEAD;
    Node *ptemp = new Node;
    ptemp->data = value;
    int i;
    for (i = 0; i < pos; ++i)
    {
        p = p->next;
    }
    ptemp->next = p->next;
    p->next = ptemp;
}

void oneWayList::deleteListAllNodes()
{
    Node *p = HEAD->next;
    Node *ptemp;
    while (p != nullptr)
    {
        ptemp = p;
        p = p->next;
        delete ptemp;
        HEAD->next = p; //？ 有没有必要加上HEAD
    }
    HEAD->next = nullptr;
}

void oneWayList::deleteOneElement(int value)
{
    Node *ptemp = find(value); //first found position
    Node *p = HEAD;
    while (p->next != ptemp)
    {
        p = p->next;
    }
    p->next = ptemp->next;
    delete ptemp;
}
