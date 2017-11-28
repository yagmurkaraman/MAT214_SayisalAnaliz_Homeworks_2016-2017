all: exe

exe: Bisection.o
	gcc Bisection.o -o exe -lm

Bisection.o: Bisection.c
	gcc -c Bisection.c

clean:
	rm *.o exe
