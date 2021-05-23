CXX = g++
CXXFLAGS = -Wall
GPROF_FLAGS = -pg

MAIN_SOURCES = $(wildcard src/*.cpp)
MAIN_HEADERS = $(wildcard src/*.hpp)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

TEST_LIBRARY_DIRECTORY = lib/Catch2
TEST_LIBRARY = $(TEST_LIBRARY_DIRECTORY)/catch_amalgamated.cpp
TEST_HEADERS = $(TEST_LIBRARY_DIRECTORY)/catch_amalgamated.hpp
TEST_SOURCES = test/test.cpp $(TEST_LIBRARY)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

sort : $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) -o sort

test : $(TEST_OBJECTS) $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) $(TEST_OBJECTS) -o test/quicksorttest