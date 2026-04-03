#ifndef STRINGINSTRUMENT_H
#define STRINGINSTRUMENT_H

#include "MusicalInstrument.h"

class StringInstrument : virtual public MusicalInstrument {
protected:
    int stringCount;
    std::string material;

public:
    StringInstrument(const std::string& n = "Unknown", double p = 0.0,
                     int strings = 4, const std::string& mat = "сталь");
    virtual ~StringInstrument();

    void play() const override;
    void printInfo() const override;

    int getStringCount() const { return stringCount; }
};

#endif
