#include "ElectricViolin.h"

ElectricViolin::ElectricViolin(const std::string& n, double p,
                               int strings, const std::string& mat,
                               int watts, bool amp,
                               const std::string& body)
    : MusicalInstrument(n, p)
    , StringInstrument(n, p, strings, mat)
    , ElectronicInstrument(n, p, watts, amp)
    , hasPickup(true)
    , bodyMaterial(body) {}

ElectricViolin::~ElectricViolin() {}

void ElectricViolin::play() const {
    std::cout << "Электроскрипка \"" << name << "\" звучит:\n    ";
    std::cout << "- Как струнная: смычок по " << stringCount
              << " струнам из " << material << "\n    ";
    std::cout << "- Как электронная: усилитель " << powerWatts << " Вт";
    if (hasPickup) {
        std::cout << " (звукосниматель активен)";
    }
    std::cout << "\n    Результат: мощное, насыщенное звучание";
}

void ElectricViolin::printInfo() const {
    MusicalInstrument::printInfo();
    std::cout << "\n    СТРУННАЯ часть: " << stringCount << " струны, материал: " << material
              << "\n    ЭЛЕКТРОННАЯ часть: " << powerWatts << " Вт, усилитель: "
              << (hasAmplifier ? "есть" : "нет")
              << "\n    ЭЛЕКТРОСКРИПКА: корпус из " << bodyMaterial
              << ", звукосниматель: есть";
}
