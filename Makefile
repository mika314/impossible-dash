TARGET=$(shell basename $$(pwd))
SOURCES=$(shell echo *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CXXFLAGS=-Wall -march=native -gdwarf-3 -std=c++1y -O3 -g $(shell pkg-config --cflags sdl2pp)
LDFLAGS=$(shell pkg-config --libs sdl2pp)
$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) $(LDFLAGS) -o $(TARGET)
%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -MT $@ -MMD -MP -MF $*.mk~
-include *.mk~
clean:
	rm -f *~
	rm -f *.o
	rm -f $(TARGET)
