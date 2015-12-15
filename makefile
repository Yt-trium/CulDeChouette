# ------------------------------
#        MAKEFILE CDC
#
#      Cyril Meyer 2015
# ------------------------------

CC=gcc
CFLAGS=-g -Wall
LDFLAGS=

all : cdc

cdc : cdc.o crap.o game.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	mv $@ bin/.

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(FLAGS)

test : all
	./bin/cdc

testhelp : all
	./bin/cdc -help

clean :
	rm *.o
	
clear : clean
	rm ./bin/cdc

doc :
	doxygen

kill :
	pkill cdc
