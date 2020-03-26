#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("Printing all passed command line arguments:\n");
	for(int i = 0; i < argc; i++) {
		printf("%s\n",argv[i]);
	}

	return 0;
}
