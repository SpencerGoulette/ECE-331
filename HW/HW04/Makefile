# Makefile for HW04
# Creates main.o, gpio.o, and the executable gpio

TARGET=gpio
OBJS=main.o gpio.o 
CFLAGS=-Wall -g -O2

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) core*

