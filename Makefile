
CXXFLAGS = -std=c++11 -Wall -O2 -g -pg
LDFLAGS = 
LIBS = 
LIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
MAINSRC = ./src/Game.cpp 


BINDIR = ./bin
OBJDIR = ./obj
SRCDIR = ./src
SRC = $(filter-out $(MAINSRC), $(shell find $(SRCDIR) -name *.cpp))
OBJ = $(subst $(SRCDIR)/, $(OBJDIR)/, $(SRC:.cpp=.o))
BIN = $(subst $(SRCDIR)/, $(BINDIR)/, $(MAINSRC:.cpp=.out))
.PHONY : all clean
.SECONDARY:
all: $(BIN) 
$(BINDIR)/%.out: $(OBJ) $(OBJDIR)/%.o
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LIB)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS)  -c $<  -o $@
clean:
	find $(OBJDIR) -name "*.o" -delete
	find $(BINDIR) -name "*.out" -delete
	rm gmon.out
server:
	$(CXX) $(CXXFLAGS) srcServeur/mainServeur.cpp srcServeur/Serveur.cpp -o  bin/LaunchServer.out $(LIB)
