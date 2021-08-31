#include <iostream>
#include "linkedlist.h"

using namespace std;


Node::Node() : sd(nullptr), nextSect(nullptr), nextExpo(nullptr), nextSpeed(nullptr) {}

Node::Node(SurveyData* sd) : sd(sd), nextSect(nullptr), nextExpo(nullptr), nextSpeed(nullptr) {}

Node::~Node() {
    if (sd) {
        delete sd;
    }
}


void Node::print() {
    cout << "Sector: #" << sd->getSect() << " " << sd->getExpo() << "% exposure, " << sd->getSpeed() << " km/hr windspeed" << endl;
}

LinkedList::LinkedList() : head(new Node()), tail(new Node()) {};

LinkedList::~LinkedList() {
    if (head) {
        destroy(head);
    }
}


void LinkedList::printValues() {

    Node* curNodeSect = head->nextSect;
    cout << setw(70) << out.fill('-') << endl;
    cout << setw(20) << "Data value" << endl;
    cout << setw(70) << out.fill('-') << endl;
    cout << "Data by Sector" << endl;
    while (curNodeSect->nextSect) {
        curNodeSect->nextSect->print();
        curNodeSect = curNodeSect->nextSect;
    }
    cout << "Data by Exposure" << endl;
    Node* curNodeExpo = head->nextExpo;
    while (curNodeExpo->nextExpo) {
        curNodeExpo->nextExpo->print();
        curNodeExpo = curNodeExpo->nextExpo;
    }
    Node* curNodeSpeed = head->nextSpeed;
    cout << "Data by Speed" << endl;
    while (curNodeSpeed->nextSpeed) {
        curNodeSpeed->nextSpeed->print();
        curNodeSpeed = curNodeSpeed->nextSpeed;
    }

    cout << "----------------------------------------------------------------------Averages per sector----------------------------------------------------------------------" << endl;
    int totalExpo = 0;
    int totalSpeed = 0;
    int count = 0;
    Node* curr = head->nextSect;

    while (curr->nextSect) 
    {
        if (curr->sd->getSect() == curr->nextSect->sd->getSect()) 
        {
            totalExpo = totalExpo + curr->sd->getExpo();
            totalSpeed = totalSpeed + curr->sd->getSpeed();
            count++;
        }
        else 
        {
            totalExpo = totalExpo + curr->sd->getExpo();
            totalSpeed = totalSpeed + curr->sd->getSpeed();
            count++;
            if (curr->nextSect->sd->getSect() - curr->sd->getSect() == 1)
            {
                cout << "Sector: #" << curr->sd->getSect() << " " << totalExpo / count << "% exposure, " << totalSpeed / count << " km/hr windspeed" << endl;
            }
            else 
            {
                cout << "Sector: #" << curr->nextSect->sd->getSect() << " -- no data -- " << endl;
            }
            totalExpo = 0;
            totalSpeed = 0;
            count = 0;
        }
        curr = curr->nextSect;
    }

    cout << "----------------------------------------------------------------------Histogram data for exposure----------------------------------------------------------------------" << endl;
    curr = head->nextExpo;
    count = 0;
    while (curr->nextExpo) 
    {
        if (curr->sd->getExpo() == curr->nextExpo->sd->getExpo()) 
        {
            count++;
        }
        else 
        {
            count++;
            cout << curr->sd->getExpo() << ", " << count << endl;
            count = 0;
        }
        curr = curr->nextExpo;
    }

        cout << "----------------------------------------------------------------------Histogram data for speed----------------------------------------------------------------------" << endl;
        curr = head->nextSpeed;
        count = 0;
        while (curr->nextSpeed) {
            if (curr->sd->getSpeed() == curr->nextSpeed->sd->getSpeed()) {
                count++;
            }
            else {
                count++;
                cout << curr->sd->getSpeed() << ", " << count << endl;
                count = 0;
            }
            curr = curr->nextSpeed;
        }
};

bool LinkedList::containsValue(int sect) {
    Node* currNode = head->nextSect;
    while (currNode) {
        if (currNode->sd->getSect() == sect) {
            return true;
        }
        currNode = currNode->nextSect;
    }
    return false;
};


void LinkedList::print() {
    Node* currNode = head->nextSect;
    while (currNode) {
        cout  << currNode->sd->getSect() << " ";
        currNode = currNode->nextSect;
    }
}

void LinkedList::removeNode(int sect)
{
    Node* currNode = head->nextSect;
    Node* prev = nullptr;

    while (currNode != nullptr)
    {
        if (currNode->sd->getSect() == sect && currNode->sd->getExpo() && currNode->sd->getSpeed())
        {
            if (currNode == head->nextSect)
            {
                head->nextSect = currNode->nextSect;
                currNode = currNode->nextSect;
            }
            else 
            {
                prev->nextSect = currNode->nextSect;
                prev->nextExpo = currNode->nextExpo;
                prev->nextSpeed = currNode->nextSpeed;
                currNode = currNode->nextSect;
            }
        }
        else 
        {
            prev = currNode;
            currNode = currNode->nextSect;
        }
    }
};


bool LinkedList::addSorted(Node*& new_node) {
    if (linkSortedSect(head->nextSect, new_node)) {
        bool ret = linkSortedExpo(head->nextExpo, new_node);
        ret |= !linkSortedSpeed(head->nextSpeed, new_node);
        return ret;
    }
    return false;
}

bool LinkedList::linkSortedSect(Node*& curr, Node*& new_node) {
    if (!curr) {
        curr = new_node;
        tail->nextSect = new_node;
        return true;
    }

    if (curr->nextSect && curr->nextSect->sd->getSect() > new_node->sd->getSect()) {
        new_node->nextSect = curr->nextSect;
        curr->nextSect = new_node;
        return true;
    }
    return linkSortedSect(curr->nextSect, new_node);
}

bool LinkedList::linkSortedExpo(Node*& curr, Node*& new_node) {
    if (!curr) {
        curr = new_node;
        tail->nextExpo = new_node;
        return true;
    }
    if (curr->nextExpo && curr->nextExpo->sd->getExpo() > new_node->sd->getExpo()) {
        new_node->nextExpo = curr->nextExpo;
        curr->nextExpo = new_node;
        return true;
    }
    return linkSortedExpo(curr->nextExpo, new_node);
}

bool LinkedList::linkSortedSpeed(Node*& curr, Node*& new_node) {
    if (!curr) {
        curr = new_node;
        tail->nextSpeed = new_node;
        return true;
    }
    if (curr->nextSpeed && curr->nextSpeed->sd->getSpeed() > new_node->sd->getSpeed()) {
        new_node->nextSpeed = curr->nextSpeed;
        curr->nextSpeed = new_node;
        return true;
    }
    return linkSortedSpeed(curr->nextSpeed, new_node);
}



void LinkedList::destroy(Node* curr) {
    if (!curr) {
        return;
    }
    destroy(curr->nextSect);
    delete curr;
    curr = nullptr;
    return;
}



