
#include <iostream>
#include "datalogger.h"

using namespace std;

void datalogger::printReport() {
    surveyList.printValues();
};

void datalogger::addData(int sect, int expo, int speed) {
    SurveyData* sd = new SurveyData(sect, expo, speed);
    Node* new_node = new Node(sd);
    if (!surveyList.addSorted(new_node)) {
        delete new_node;
        new_node = nullptr;
    }
};


void datalogger::removeSector(int sect) {
    surveyList.removeNode(sect);
};

bool datalogger::containsSector(int sect) {
    return surveyList.containsValue(sect);
};

void datalogger::printSectorList() {
    surveyList.print();
};
