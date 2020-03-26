# Makefile for HW04
# Creates main.o, gpio.o, and the executable gpio

TARGET=wwv
OBJS=main.o gpio.o wwv.o
CFLAGS=-Wall -g -O2

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) core*

