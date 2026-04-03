#ifndef ELECTRONICINSTRUMENT_H
#define ELECTRONICINSTRUMENT_H

#include "MusicalInstrument.h"

class ElectronicInstrument : virtual public MusicalInstrument {
protected:
    int powerWatts;
    bool hasAmplifier;

public:
    ElectronicInstrument(const std::string& n = "Unknown", double p = 0.0,
                         int watts = 50, bool amp = true);
    virtual ~ElectronicInstrument();

    void play() const override;
    void printInfo() const override;

    int getPower() const { return powerWatts; }
};

#endif
