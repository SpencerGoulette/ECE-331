#ifndef WWV_H
#define WWV_H

// includes to be used
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "gpio.h"

// prototype functions
uint32_t encodebit(uint32_t gpio, uint32_t t_high);
uint32_t encodedatetime(uint32_t gpio);

#endif
