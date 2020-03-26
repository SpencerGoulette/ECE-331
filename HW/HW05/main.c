#include "gpio.h"
#include "wwv.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Run tests on gpio.c functions
int main(int argc, char *argv[])
{
	uint32_t retvalue;	

	retvalue = encodedatetime(4);
	if (retvalue != 0) {
		printf("Error encoding!\n");
		return -1;
	}

	return 0;
}
