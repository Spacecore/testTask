#ifndef TAMPLITUDEANALYZE_H
#define TAMPLITUDEANALYZE_H
#include "tsignalline.h"
#include "tgenerator.h"

class TAmplitudeAnalyzer
{
private:
    TSignalLine *amplitudeAnalyzerSignalLine_;
    TGenerator *amplitudeGenerator_;
    double* frequencyArray_;
    double* amplitudeArray_;
    int arrayLength_;
public:
    TAmplitudeAnalyzer();
    ~TAmplitudeAnalyzer();
    void setSignalLine(TSignalLine* aSignalLine);
    void cleanMemory();
    TSignalLine* getSignalLine();
    double DFT();
    double getFrequancy(double aFrequancy);
    void add(TSignalLine* aSignalLine, TSignalLine* aRezultSignalLine);
    double* getAmplitudeArray();
    double* getFrequancyArray();
    double getAmplitude(double aFrequancy);
    int getArraySize();
};

#endif // TAMPLITUDEANALYZE_H
