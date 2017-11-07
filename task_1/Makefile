all: task_1

task_1: main.o io.o
	gcc -o task_1 main.o io.o
main.o: main.c defs.h io.h
	gcc -c -g main.c
io.o: io.c defs.h io.h
	gcc -c -g io.c
clean:
	rm -rf main.o task_1 io.o hello_world.o hello_world
