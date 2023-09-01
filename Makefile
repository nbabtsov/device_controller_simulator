all: echo-driver.o device-controller.o
	gcc echo-driver.o -o echo-driver -lm

echo-driver.o: echo-driver.c
	gcc -c echo-driver.c

device-controller.o: device-controller.h
	gcc -c device-controller.h
debug:
	gcc -o echo-driver -g echo-driver.c

clean:
	rm *.o *.h.ghc echo-driver 

