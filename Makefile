CC = avr-gcc
CFLAGS = -g -Os -Wall -Werror -Wextra -std=c99 -DF_CPU=16000000UL -mmcu=atmega328p
INCLUDES = -I/usr/lib/avr/include
LIBRARIES =	

# File variables
SRC_DIR = src
OUT_DIR = out
LIB_DIR = lib

SOURCES = $(SRC_DIR)/hc_sr04.c
OBJECTS = $(OUT_DIR)/hc_sr04.o
TARGET = $(LIB_DIR)/libhcsr04.a

all: $(TARGET)

compile: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(LIB_DIR)
	avr-ar rcs $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf out lib

.PHONY: clean