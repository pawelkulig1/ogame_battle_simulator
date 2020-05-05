FILES=  static_structure.o \
		structure.o \
		battle.o \
		structure_builder.o

all: main.cpp $(FILES)
	$(CXX) main.cpp $(FILES) -o main.o


