#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Divides by two until it can't anymore
// returns how many times it had to divide by 2
uint32_t logbase2(uint32_t num)
{
	uint32_t sum = 0;
	if(num > 1) sum = 1 + logbase2(num / 2);
	return sum;
}

int main()
{
	// Creates an array with ten test integers
	uint32_t test[10] = {0,1,2,3,4,8,13,64,420420,4294967295};

	// Tests each of the test integers
	for(int i = 0; i < 10; i++) printf("The log base 2 of %u is: %u\n",test[i],logbase2(test[i]));

	return 0;
}
