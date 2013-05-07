PROGRAM = jpm
CC = g++
CFLAGS = -I. -L/usr/local/lib -lcurl
OBJDIR = obj
SRCDIR = src
SRCFILES := $(filter-out $(SRCDIR)/main.cpp, $(wildcard src/*.cpp))
OBJFILES := $(addprefix obj/,$(notdir $(SRCFILES:.cpp=.o)))


all: $(PROGRAM)

clean: 
	@rm -rf $(OBJDIR)/*.o
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CC) -c -o $@ $< 
	
$(PROGRAM): $(OBJFILES)
	$(CC) -o $@ $(CFLAGS) $^ $(SRCDIR)/main.cpp
	
vars:
	echo $(SRCFILES)
	
inc: 
	echo $(CFLAGS)