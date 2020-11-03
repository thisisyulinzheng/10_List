main: main.o power_level.o
	gcc -o main main.o power_level.o

main.o: main.c power_level.h
	gcc -c main.c

power_level.o: power_level.c power_level.h
	gcc -c power_level.c 

run:
	./main