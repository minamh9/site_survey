
#ifndef WEATHERDATA_H
#define WEATHERDATA_H

class SurveyData {
public:
    SurveyData();
    SurveyData(int, int, int);

    int getSect() const;
    int getExpo() const;
    int getSpeed() const;

private:
    int sect;
    int expo;
    int speed;

};
#endif

