CC = avr-gcc
CFLAGS = -mmcu=atmega328p -DF_CPU=16000000UL -Wall -Os
OBJCOPY = avr-objcopy
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = main

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET).elf: $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@
	$(OBJCOPY) -j .text -j .data -O ihex -R .eeprom $(BIN_DIR)/$(TARGET).o $(BIN_DIR)/$(TARGET).hex

flash:
	avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:$(BIN_DIR)/$(TARGET).hex

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: flash clean

