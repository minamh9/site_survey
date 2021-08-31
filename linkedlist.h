
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "surveydata.h"

class Node {
public:
    Node();
    Node(SurveyData*);
    ~Node();
    Node(const Node&);
    SurveyData* sd;
    Node* nextSect;
    Node* nextExpo;
    Node* nextSpeed;
    bool remove;
    void print();
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);


    bool addSorted(Node*&);
    void printValues();
    bool containsValue(int sect);
    void print();
    void removeNode(int sect);
private:
    int size;
    Node* head, * tail;
    bool linkSortedSect(Node*&, Node*&);
    bool linkSortedExpo(Node*&, Node*&);
    bool linkSortedSpeed(Node*&, Node*&);

    void destroy(Node*);
    bool copy(Node*&, Node*);
};

#endif
