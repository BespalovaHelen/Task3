#include "StringInstrument.h"

StringInstrument::StringInstrument(const std::string& n, double p,
                                   int strings, const std::string& mat)
    : MusicalInstrument(n, p), stringCount(strings), material(mat) {}

StringInstrument::~StringInstrument() {}

void StringInstrument::play() const {
    std::cout << "Струнный инструмент \"" << name << "\" звучит: "
              << "смычок проводит по " << stringCount << " струнам из " << material;
}

void StringInstrument::printInfo() const {
    MusicalInstrument::printInfo();
    std::cout << ", тип: струнный, струн: " << stringCount
              << ", материал: " << material;
}
