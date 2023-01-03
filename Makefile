#SERIALPORT = /dev/tty.usbmodem141301
SOURCEFILE = lab4.c
CLOCKSPEED = 16000000
PROGRAMMER = usbtiny

begin:	main.hex

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=atmega328p main.elf

main.elf: $(SOURCEFILE)
	avr-gcc -Wall -Os -DF_CPU=$(CLOCKSPEED) -mmcu=atmega328p -o main.elf $(SOURCEFILE)

flash:	begin
	avrdude -c $(PROGRAMMER) -p atmega328p -U flash:w:main.hex:i
#avrdude -c arduino -b 115200 -P $(SERIALPORT) -p atmega328p -U flash:w:main.hex:i

