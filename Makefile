CXX = g++
CXXFLAGS = -O2 -MMD
LDLIBS = -lGL -lGLU -lglut

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))



all: micromachines


run: micromachines
	./micromachines


micromachines: $(OBJ_FILES)
	$(CXX) -o micromachines $(OBJ_FILES) $(CXXFLAGS) $(LDLIBS)


obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<



clean:
	rm -rf obj/*.o micromachines


