all: main

main: main.c stack.h stack.o
	cc -o main main.c stack.o

stack.o: stack.h stack.c
	cc -c -o stack.o stack.c

sizeof: sizeof.c
	cc -o sizeof sizeof.c

rmbin:
	-rm main
	-rm sizeof
