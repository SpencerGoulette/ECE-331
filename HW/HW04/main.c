#include "gpio.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Run tests on gpio.c functions
int main(int argc, char *argv[])
{
	// test case for gpio 17
	uint32_t num4 = 4;
	uint32_t iter;
	
	// turn on and off gpio output five times to blink LED
	GPIO_export(num4);
	GPIO_setdir(num4,"out");
	for (iter = 0; iter < 5; iter++) {
		GPIO_setval(num4,0);
		usleep(500000);
		GPIO_setval(num4,1);
		usleep(500000);
	}
	GPIO_unexport(num4);

	return 0;
}
