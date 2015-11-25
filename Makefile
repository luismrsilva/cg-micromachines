CXX = g++
CXXFLAGS = -O2 -MMD -Wall -pedantic -ggdb -std=c++11
LDLIBS = -lGL -lGLU -lglut

HPP_FILES := $(wildcard src/*.hpp)
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))


all: micromachines

-include $(OBJ_FILES:.o=.d)


quiet-run: micromachines
	./micromachines > /dev/null

run: micromachines
	./micromachines


micromachines: $(OBJ_FILES) $(HPP_FILES)
	$(CXX) -o micromachines $(OBJ_FILES) $(CXXFLAGS) $(LDLIBS)


obj/%.o: src/%.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

debug: CXXFLAGS+=-g -DDEBUG
debug: all $(OBJ_FILES) $(HPP_FILES)


clean:
	rm -rf obj/*.o obj/*.d micromachines


