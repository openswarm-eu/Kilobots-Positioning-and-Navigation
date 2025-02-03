
.PHONY: docs ants2024
KILOLIB = build/kilolib.a
ants2024: build/ants2024.elf build/ants2024.hex build/ants2024.lss

CC = avr-gcc
AVRAR = avr-ar
AVROC = avr-objcopy
AVROD = avr-objdump
AVRUP = avrdude

PFLAGS = -P usb -c avrispmkII # user to reprogram OHC
CFLAGS = -mmcu=atmega328p -Wall -gdwarf-2 -O3 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -DF_CPU=8000000
ASFLAGS = $(CFLAGS)

FLASH = -R .eeprom -R .fuse -R .lock -R .signature
EEPROM = -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0  

%.lss: %.elf
	$(AVROD) -d -S $< > $@

%.hex: %.elf
	$(AVROC) -O ihex $(FLASH) $< $@

%.eep: %.elf
	$(AVROC) -O ihex $(EEPROM) $< $@

%.bin: %.elf
	$(AVROC) -O binary $(FLASH) $< $@ 

build:
	mkdir -p $@

message_send.o: message_send.S
	$(CC) $(CFLAGS) -c -o $@ $<

$(KILOLIB): kilolib.o message_crc.o message_send.o | build
	$(AVRAR) rcs $@ kilolib.o message_crc.o message_send.o 
	rm -f *.o

build/ants2024.elf: ants2024.c $(KILOLIB) | build
	$(CC) $(CFLAGS) -o $@ $< $(KILOLIB) 

docs:
	cat message.h kilolib.h message_crc.h | grep -v "^\#" > docs/kilolib.h
	(cd docs; doxygen)

clean:
	rm -fR build
