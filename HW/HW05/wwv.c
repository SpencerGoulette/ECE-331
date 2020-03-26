#include "wwv.h"

// Encodes bit on gpio pin based on the time high passed
uint32_t encodebit(uint32_t gpio, uint32_t t_high)
{
	// timespec structs to get accurate timing
	struct timespec start;
	struct timespec finish;
	struct timespec start100hz;
	struct timespec finish100hz;

	// If time high is 0 just set output of gpio low for 1 sec
	if (t_high == 0) {
		clock_gettime(CLOCK_REALTIME, &start);
		if(gpio_setvalue(gpio,0) != 0) {
			printf("Unable to set gpio!\n");
		}
		while ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) <= 1.0) {
			usleep(10);
			clock_gettime(CLOCK_REALTIME, &finish);
		}
		return 0;
	}

	// If time high is not 0, keep gpio high for that long then keep it low for the remaining second
	// Multiple check for if time is over a second and if tim is above time high
	else {
		clock_gettime(CLOCK_REALTIME, &start);
		while ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) <= ((double)t_high / 1000.0)) {

			// Time high for the 100Hz signal
			clock_gettime(CLOCK_REALTIME, &start100hz);
			if(gpio_setvalue(gpio,1) != 0) {
				printf("Unable to set gpio!\n");
			}
			while ((((double)finish100hz.tv_sec + (double)finish100hz.tv_nsec/(double)1000000000) - ((double)start100hz.tv_sec + (double)start100hz.tv_nsec/(double)1000000000)) <= 0.005) {
				usleep(10);
				clock_gettime(CLOCK_REALTIME, &finish100hz);
				clock_gettime(CLOCK_REALTIME, &finish);
				if ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) >= ((double)t_high / 1000.0)) break; 
			}
			if ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) >= ((double)t_high / 1000.0)) break;
			// Time Low for the 100Hz signal
			clock_gettime(CLOCK_REALTIME, &start100hz);
			if(gpio_setvalue(gpio,0) != 0) {
				printf("Unable to set gpio!\n");
			}
			while ((((double)finish100hz.tv_sec + (double)finish100hz.tv_nsec/(double)1000000000) - ((double)start100hz.tv_sec + (double)start100hz.tv_nsec/(double)1000000000)) <= 0.005) {
				usleep(10);
				clock_gettime(CLOCK_REALTIME, &finish100hz);
				clock_gettime(CLOCK_REALTIME, &finish);
				if ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) >= ((double)t_high / 1000.0)) break;
			}
		}
		if(gpio_setvalue(gpio,0) != 0) {
			printf("Unable to set gpio!\n");
		}
		while ((((double)finish.tv_sec + (double)finish.tv_nsec/(double)1000000000) - ((double)start.tv_sec + (double)start.tv_nsec/(double)1000000000)) <= 1.0) {
			usleep(10);
			clock_gettime(CLOCK_REALTIME, &finish);
		}
		
		return 0;
	}
}

// Gets data and time and encodes it for wwv
uint32_t encodedatetime(uint32_t gpio)
{
	uint32_t i;					// Iterator
	uint32_t retvalue;			// Return value check
	uint32_t array[60] = {0};	// Hold bits for wwv
	uint32_t yearones;			// Date and Time variables
	uint32_t minones;
	uint32_t mintens;
	uint32_t hourones;
	uint32_t hourtens;
	uint32_t doyones;
	uint32_t doytens;
	uint32_t doyhundreds;
	time_t now;
	struct tm *local;

	// Exports and sets gpio
	gpio_export(gpio);
	gpio_setdirection(gpio, "out");

	// Gets date and time
	time(&now);
	local = localtime(&now);

	// Gets ones, tens and hundreds place for date and time
	yearones = (local->tm_year + 1900) % 10;
	minones = (local->tm_min) % 10;
	mintens = ((local->tm_min) % 100) / 10;
	hourones = (local->tm_hour) % 10;
	hourtens = ((local->tm_hour) % 100) / 10;
	doyones = (local->tm_yday) % 10;
	doytens = ((local->tm_yday) % 100) / 10;
	doyhundreds = ((local->tm_yday) % 1000) / 100;

	// Places 1s, 2s, 4s, and 8s bit in wwv array
	for (i = 4; i < 8; i++) {
		array[i] = ((yearones & ((i - 4) << 0x01)) ? 470 : 170);
		array[i + 6] = ((minones & ((i - 4) << 0x01)) ? 470 : 170);
		array[i + 16] = ((hourones & ((i - 4) << 0x01)) ? 470 : 170);
		array[i + 26] = ((doyones & ((i - 4) << 0x01)) ? 470 : 170);
		array[i + 31] = ((doytens & ((i - 4) << 0x01)) ? 470 : 170);
	}

	// Places 1s, 2s, and 4s bit in wwv array
	for (i = 15; i < 18; i++) {
		array[i] = ((mintens & ((i - 15) << 0x01)) ? 470 : 170);
		array[i + 10] = ((hourtens & ((i - 15) << 0x01)) ? 470 : 170);
	}

	// Places 1s, and 2s bit in wwv array
	for (i = 40; i < 42; i++) {
		array[i] = ((doyhundreds & ((i - 40) << 0x01)) ? 470 : 170);
	}

	// Places P indentifiers in wwv array
	for (i = 1; i < 5; i++) {
		array[i * 10 - 1] = 770;
	}

	// Prints time and date for checking purposes
	printf("Beginning to encode Year: %d, DoY: %d, Time: %d:%d", local->tm_year + 1900, local->tm_yday, local->tm_hour, local->tm_min);

	// Prints and encodes bits for wwv
	for (i = 0; i < 60; i++) {
		if ((i % 10) == 0) {
			if (i == 50) {
				printf("\nEncoding Segment 0\n");
			}
			else {
				printf("\nEncoding Segment %d\n", (i / 10) + 1);
			}
		}

		retvalue = encodebit(gpio, array[i]);
		if (retvalue != 0) {
			printf("Couldn't Encode Time Index %d!\n", i);
			return -1;
		}
		else {
			if (array[i] == 770) {
				printf("Time Index %d: P\n", i);
			}
			else if (array[i] == 0) {
				printf("Time Index %d: 0\n", i);
			}
			else {
				printf("Time Index %d: %d\n", i, ((array[i] == 470) ? 1 : 0));
			}
		}
	}

	// Unexports gpio
	gpio_unexport(gpio);
	return 0;
}
