####################### Makefile Template ##########################
# Compiler settings - Can be customized.
CC = /opt/rh/gcc-toolset-10/root/usr/bin/g++
CXXFLAGS = -fcoroutines -std=c++2a -g -gdwarf-2 -pthread -Wall
LDFLAGS =

# Makefile settings - Can be customized.
APPNAME = myapp
EXT = .cpp
SRCDIR = .
OBJDIR = .

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
####################### Targets beginning here #######################
all: $(APPNAME)
# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@
# Includes all .h files
-include $(DEP)
# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<
################### Test ###############################################
test: all
	./$(APPNAME)
################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)
