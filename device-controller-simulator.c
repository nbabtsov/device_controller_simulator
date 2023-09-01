#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "device-controller.h"

char* message = "Hello, World!\n";
int write_value = -1;

void start() {
	int size = strlen(message);
	int next = 0;
	srand(0);
	for (int i=0; i<225; i++) {
		usleep(10000);
		if ((rand() % 10) < 4) {
			if (write_value != -1) {
				putchar(write_value);
				write_value = -1;
				write_done_interrupt();
			}
		} else {
			read_interrupt(message[next]);
			next = (next + 1) % size;
		}
	}
	printf("\n");
}

void write_device(int c) {
	write_value = c;
}

