#include "gpio.h"

// Export gpio
uint32_t gpio_export(uint32_t gpio)
{
	int32_t f;	// file
	char string[10];	// write
	sprintf(string,"%u",gpio);	// change gpio from int to string

	// open export file
	f = open("/sys/class/gpio/export",O_WRONLY);
	if (f < 0) {
		printf("Could not open export\n");
		return 1;
	}

	// export gpio
	if (write(f,string,strlen(string)) < 0) {
		printf("Could not export\n");
		return 2;
	}

	// close and wait
	close(f);
	usleep(50000);

	return 0;
}

// Unexport gpio
uint32_t gpio_unexport(uint32_t gpio)
{
	int32_t f;	// file
	char string[10];	// write
	sprintf(string,"%u",gpio);	// change gpio from int to string

	// open unexport file
	f = open("/sys/class/gpio/unexport",O_WRONLY);
	if (f < 0) {
		printf("Could not open unexport\n");
		return 1;
	}

	// unexport gpio
	if(write(f,string,strlen(string)) < 0) {
		printf("Could not unexport\n");
		return 2;
	}

	// close and wait
	close(f);
	usleep(50000);

	return 0;
}

// Set value for gpio
uint32_t gpio_setvalue(uint32_t gpio, uint32_t val)
{
	int32_t f;	// file
	char string[50];	// write
	char string1[10];	// value
	sprintf(string,"/sys/class/gpio/gpio%u/value",gpio);	// change gpio from int to string
	sprintf(string1,"%u",val);	// change val from int to string

	// open value file
	f = open(string,O_WRONLY);
	if (f < 0) {
		printf("Could not open value\n");
		return 1;
	}

	// write value
	if(write(f,string1,strlen(string1)) < 0) {
		printf("Could not set value\n");
		return 2;
	}

	// close and wait
	close(f);
	usleep(50);

	return 0;
}

// Set direction for gpio
uint32_t gpio_setdirection(uint32_t gpio, char dir[])
{
	int32_t f;	// file
	char string[50];	// write
	sprintf(string,"/sys/class/gpio/gpio%u/direction",gpio);	// change gpio from int to string

	// open direction file
	f = open(string,O_WRONLY);
	if (f < 0) {
		printf("Could not open direction\n");
		return 1;
	}

	// write value
	if (write(f,dir,strlen(dir)) < 0) {
		printf("Could not set direction\n");
		return 2;
	}

	// close and wait
	close(f);
	usleep(50);

	return 0;
}


