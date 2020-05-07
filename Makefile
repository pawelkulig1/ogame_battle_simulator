FILES=  static_structure.o \
		structure.o \
		battle.o \
		structure_builder.o \
		random_number_generator.o

CXXFLAGS=--std=c++11 -g

all: main.cpp $(FILES)
	$(CXX) main.cpp $(FILES) $(FLAGS) -g -o main.o

clean:
	rm -rf *.o



