PROGRAM=s3d
CC=g++

FW = -framework GLUT -framework OpenGL 
SRCS := $(filter-out src/main.cpp, $(wildcard src/*.cpp))
OBJS := $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))

all: $(PROGRAM)

obj/%.o: src/%.cpp src/%.h
	g++ -o $@ -c $<

$(PROGRAM): $(OBJS)
	$(CC) $(FW) -o $(PROGRAM) src/main.cpp $(OBJS)
	
clean: 
	@rm -rf ./obj/*
