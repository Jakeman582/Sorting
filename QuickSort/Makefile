CXX = g++
CXXFLAGS = -Wall
GPROF_FLAGS = -pg
DEBUG_FLAGS = -g

EXE = sort debug_sort test/quicksorttest profile_sort
OUTPUT = profiling/timings.txt gmon.out profiling/profile.txt

MAIN_SOURCES = $(wildcard src/*.cpp)
MAIN_HEADERS = $(wildcard src/*.hpp)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

LIB_SOURCES = $(wildcard lib/*.cpp)
LIB_HEADERS = $(wildcard lib/*.hpp)
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

CATCH2 = ext/Catch2
CATCH2_SOURCES = $(CATCH2)/catch_amalgamated.cpp
CATCH2_HEADERS = $(CATCH2)/catch_amalgamated.hpp
TEST_SOURCES = test/test.cpp $(CATCH2_SOURCES)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

PROFILE_INPUT = input/1000000_1.txt
PROFILE_OUTPUT = /dev/null

all : sort debug test profile_sort

sort : $(MAIN_OBJECTS) $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) $(LIB_OBJECTS) -o sort

debug : $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(MAIN_SOURCES) $(LIB_OBJECTS) -o debug_sort

test : $(TEST_OBJECTS) $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(LIB_OBJECTS) -o test/quicksorttest

profile : $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) $(GPROF_FLAGS) $(MAIN_SOURCES) $(LIB_OBJECTS) -o profile_sort

profile_sort : profile
	profiling/profile.sh
	./profile_sort $(PROFILE_INPUT) > $(PROFILE_OUTPUT)
	gprof ./profile_sort > profiling/profile.txt

clean :
	rm $(EXE) $(OUTPUT) $(MAIN_OBJECTS) $(LIB_OBJECTS) $(TEST_OBJECTS)