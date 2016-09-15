FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm
COMPILLER=g++

all: start

start: vector.o queue.o main.o
	$(COMPILLER) $(FLAGS) -o da-lab1 vector.o queue.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

vector.o: vector.cpp
	$(COMPILLER) -c $(FLAGS) vector.cpp

queue.o: queue.cpp
	$(COMPILLER) -c $(FLAGS) queue.cpp

clear:
	-rm -f *.o *.gch da-lab1
