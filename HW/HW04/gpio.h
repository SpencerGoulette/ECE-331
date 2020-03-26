#ifndef GPIO_H
#define GPIO_H

// includes to be used
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// gpio function prototypes
uint32_t GPIO_export(uint32_t gpio);
uint32_t GPIO_unexport(uint32_t gpio);
uint32_t GPIO_setval(uint32_t gpio, uint32_t val);
uint32_t GPIO_setdir(uint32_t gpio, char dir[]);

#endif
