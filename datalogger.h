

#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <ostream>
#include "linkedlist.h"

class datalogger {
public:
    //    datalogger();

    //    ~datalogger();
    void addData(int, int, int); //add a data item to the logger

    void removeSector(int); //remove all survey data for the given sector

    bool containsSector(int); //determine if the given sector data is already in the logger

    void printReport(); // print a report

    void printSectorList(); // print a list of all of the sectors in the logger

private:
    static const bool DEBUG = false;
    LinkedList surveyList;
};

#endif

