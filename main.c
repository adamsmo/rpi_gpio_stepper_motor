#include <bcm2835.h>

#include <stdio.h>
#include <string.h>

#define PIN1 RPI_GPIO_P1_11
#define PIN2 RPI_GPIO_P1_12
#define PIN3 RPI_GPIO_P1_15
#define PIN4 RPI_GPIO_P1_16

void rotateCW(int sleep){
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, HIGH);
	delay(sleep);
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, HIGH);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, HIGH);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
	bcm2835_gpio_write(PIN1, HIGH);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
}

void rotateCCW(int sleep){
	bcm2835_gpio_write(PIN1, HIGH);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, HIGH);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, HIGH);
	bcm2835_gpio_write(PIN4, LOW);
	delay(sleep);
	bcm2835_gpio_write(PIN1, LOW);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
	bcm2835_gpio_write(PIN4, HIGH);
	delay(sleep);
}

int main(int argc, char **argv)
{
    if (!bcm2835_init())
	return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN3, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN4, BCM2835_GPIO_FSEL_OUTP);

    // cicle
    int sleep = 4;
    int i=0;

float degree;
sscanf (argv[2], "%f", &degree);
   
if(strcmp("CW",argv[1])){
    for(i=0;i<512*(degree/360.0);i++){
	rotateCW(sleep);
    }
}else if (strcmp("CCW",argv[1])){
    for(i=0;i<512*(degree/360.0);i++){
	rotateCCW(sleep);
    }
}

    bcm2835_gpio_write(PIN1, LOW);
    bcm2835_gpio_write(PIN2, LOW);
    bcm2835_gpio_write(PIN3, LOW);
    bcm2835_gpio_write(PIN4, LOW);

    return 0;
}
