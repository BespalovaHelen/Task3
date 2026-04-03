CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = music_program
SOURCES = MusicalInstrument.cpp StringInstrument.cpp ElectronicInstrument.cpp ElectricViolin.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) -lm

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
