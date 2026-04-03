#ifndef ELECTRICVIOLIN_H
#define ELECTRICVIOLIN_H

#include "StringInstrument.h"
#include "ElectronicInstrument.h"

class ElectricViolin : public StringInstrument, public ElectronicInstrument {
private:
    bool hasPickup;
    std::string bodyMaterial;

public:
    ElectricViolin(const std::string& n = "Yamaha EV-204", double p = 50000.0,
                   int strings = 4, const std::string& mat = "сталь",
                   int watts = 100, bool amp = true,
                   const std::string& body = "клен");
    ~ElectricViolin();

    void play() const override;
    void printInfo() const override;
};

#endif
