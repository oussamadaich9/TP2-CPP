CXX = g++
CXXFLAGS = -Wall -std=c++11
SOURCES = date.cpp client.cpp chambre.cpp hotel.cpp reservation.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = hotel

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
