#include "ElectronicInstrument.h"

ElectronicInstrument::ElectronicInstrument(const std::string& n, double p,
                                           int watts, bool amp)
    : MusicalInstrument(n, p), powerWatts(watts), hasAmplifier(amp) {}

ElectronicInstrument::~ElectronicInstrument() {}

void ElectronicInstrument::play() const {
    std::cout << "Электронный инструмент \"" << name << "\" звучит: "
              << "сигнал идёт через усилитель мощностью " << powerWatts << " Вт";
    if (!hasAmplifier) {
        std::cout << " (усилитель отключён)";
    }
}

void ElectronicInstrument::printInfo() const {
    MusicalInstrument::printInfo();
    std::cout << ", тип: электронный, мощность: " << powerWatts << " Вт"
              << ", усилитель: " << (hasAmplifier ? "есть" : "нет");
}
