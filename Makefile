.POSIX:

include config.mk

#---------------------------------------------

all: optimise

#-----------------------------------------------

optimise:
	$(COMPILER) $(FILE) $(FLAGS) $(LIBS) -o $(DIST)/binary

build:
	$(COMPILER) $(FILE) $(EXTRA) $(LIBS) -o $(DIST)/binary

.PHONY: all build optimise
