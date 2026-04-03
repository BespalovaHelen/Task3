#include "MusicalInstrument.h"

MusicalInstrument::MusicalInstrument(const std::string& n, double p)
    : name(n), price(p) {}

MusicalInstrument::~MusicalInstrument() {}

void MusicalInstrument::printInfo() const {
    std::cout << "Инструмент: " << name << ", цена проката: " << price << " руб.";
}
