#ifndef MUSICALINSTRUMENT_H
#define MUSICALINSTRUMENT_H

#include <string>
#include <iostream>

class MusicalInstrument {
protected:
    std::string name;
    double price;
    
public:
    MusicalInstrument(const std::string& n = "Unknown", double p = 0.0);
    virtual ~MusicalInstrument();
    
    // Чистая виртуальная функция — звучание инструмента для концерта
    virtual void play() const = 0;
    
    virtual void printInfo() const;
    
    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

#endif
