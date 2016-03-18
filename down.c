// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink -l rt blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -l rt -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley (mikem@open.com.au)
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include <bcm2835.h>

// Blinks on RPi pin GPIO 11
#define PIN1 RPI_GPIO_P1_11
#define PIN2 RPI_GPIO_P1_12
#define PIN3 RPI_GPIO_P1_15
#define PIN4 RPI_GPIO_P1_16

int main(int argc, char **argv)
{
    if (!bcm2835_init())
	return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN3, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN4, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_write(PIN1, LOW);
    bcm2835_gpio_write(PIN2, LOW);
    bcm2835_gpio_write(PIN3, LOW);
    bcm2835_gpio_write(PIN4, LOW);
    
    return 0;
}
