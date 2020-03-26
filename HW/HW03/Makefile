# Makefile for fileinfo.c

TARGET=fileinfo
OBJS=fileinfo.o
CFLAGS=-Wall -g
SOURCES=fileinfo.c

all: $(TARGET)
$(TARGET):
	gcc -o $(TARGET) $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(TARGET) $(OBJS) core*
