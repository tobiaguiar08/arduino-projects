# Makefile for compiling and flashing C code on Arduino Uno

# Compiler and Flags
CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Source File
SRC = main.c

# Output File
HEX = program.hex

# Compile C code and generate ELF and Intel Hex files
all: $(HEX)

$(HEX): $(SRC:.c=.elf)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(SRC:.c=.elf): $(SRC)
	$(CC) -mmcu=atmega328p -Os -o $@ $<

# Flash the Arduino board
flash: $(HEX)
	$(AVRDUDE) -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:$(HEX)

# Clean the project
clean:
	rm -f *.elf *.hex

.PHONY: all flash clean


