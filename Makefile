task_1: main.o io.o
	gcc -o task_1 main.o io.o
main.o: main.c defs.h io.h
	gcc -c -g main.c
io.o: io.c defs.h io.h
	gcc -c -g io.c
hello_world: hello_world.o
	gcc -o hello_world hello_world.o
hello_world.o: hello_world.c
	gcc -c hello_world.c
clean:
	rm -rf main.o task_1 io.o hello_world.o hello_world
