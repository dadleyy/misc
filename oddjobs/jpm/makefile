PROGRAM = jpm
CC = g++
CFLAGS = -I.
DEPS = src/jpm.h
OBJDIR = obj
CPPDIR = src

all: $(OBJDIR)/*.o

clean: 
	@rm -rf $(OBJDIR)/*.o
	
$(OBJDIR)/%.o: $(CPPDIR)/*.cpp $(CPPDIR)/*.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(PROGRAM): $(OBJDIR)/*.o
	@rm $(PROGRAM)
	$(CC) -o $@ $(CPPDIR)/main.cpp $(CFLAGS) $^