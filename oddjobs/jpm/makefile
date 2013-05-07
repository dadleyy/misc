PROGRAM = jpm
CC = g++
CFLAGS = -I.

OBJDIR = obj
SRCDIR = src

DEPS = obj/jpm.o \
	   obj/jpm-connection.o

all:

clean: 
	@rm -rf $(OBJDIR)/*.o
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(PROGRAM): $(DEPS)
	$(CC) -o $@ $(SRCDIR)/main.cpp $(CFLAGS) $^