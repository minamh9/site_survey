#include "surveydata.h"

SurveyData::SurveyData() : sect(0), expo(0), speed(0) {};

SurveyData::SurveyData(int _sect, int _expo, int _speed) : sect(_sect), expo(_expo), speed(_speed) {};


int SurveyData::getSect() const {
    return sect;
}

int SurveyData::getExpo() const {
    return expo;
}

int SurveyData::getSpeed() const {
    return speed;
}
