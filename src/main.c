#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Lcd.h"

// Lcd.h ve Lcd.c kaynak
// http://www.mcu-turkey.com/stellaris-launchpad-16x2-lcd/

void init_port_E()
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; // Port E’yi aktiflestir
	delay = SYSCTL_RCGC2_R; 	  // Zaman gecirmek icin
	GPIO_PORTE_DIR_R |= 0x1E;	  // PE 4,3,2,1 pinlerini cikis yap
	GPIO_PORTE_AFSEL_R &= ~0x1E;  // PE 4,3,2,1 pinlerini alternatif fonksiyonunu 0 yap
	GPIO_PORTE_DEN_R |= 0x1E;	  // PE 4,3,2,1 pinlerini aktiflestir
}

void islem1(){

	volatile unsigned long delay;

		GPIO_PORTE_DATA_R |= 0x02;
		GPIO_PORTE_DATA_R &= ~(0x04);
		GPIO_PORTE_DATA_R &= ~(0x08);
		GPIO_PORTE_DATA_R &= ~(0x10);

	for (delay = 0 ; delay < 1000000 ; delay++);


    SysCtlClockSet(
                    SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN);


    Lcd_init();
    Lcd_Cmd(0x0C);

    Lcd_Imlec(1,3);
    Lcd_Yaz("Kocaeli Uni");

    for (delay = 0 ; delay < 8000000 ; delay++);

    Lcd_Imlec(2,2);
    Lcd_Yaz("Berkay Bostan");

    for (delay = 0 ; delay < 12000000 ; delay++);

    Lcd_Clean();
    GPIO_PORTE_DATA_R &= ~(0x02);

}

void islem2(){

	volatile unsigned long delay;

		GPIO_PORTE_DATA_R |= 0x04;
		GPIO_PORTE_DATA_R &= ~(0x02);
		GPIO_PORTE_DATA_R &= ~(0x08);
		GPIO_PORTE_DATA_R &= ~(0x10);

		for (delay = 0 ; delay < 1000000 ; delay++);


    SysCtlClockSet(
                    SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN);


    Lcd_init();
    Lcd_Cmd(0x0C);

    Lcd_Imlec(2,2);
    Lcd_Yaz("Berkay Bostan");

    for (delay = 0 ; delay < 8000000 ; delay++);

    Lcd_Imlec(1,3);
    Lcd_Yaz("Kocaeli Uni");

    for (delay = 0 ; delay < 12000000 ; delay++);

    Lcd_Clean();
    GPIO_PORTE_DATA_R &= ~(0x04);

}

void islem3(){

	volatile unsigned long delay;

		GPIO_PORTE_DATA_R |= 0x08;
		GPIO_PORTE_DATA_R &= ~(0x02);
		GPIO_PORTE_DATA_R &= ~(0x04);
		GPIO_PORTE_DATA_R &= ~(0x10);

		for (delay = 0 ; delay < 1000000 ; delay++);


    SysCtlClockSet(
                    SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN);


    int i;

    Lcd_init();
    Lcd_Cmd(0x0C);

    Lcd_Imlec(1,1);
    Lcd_Yaz("Kocaeli Uni");

    for(i=0; i<40; i++){

    	Lcd_Cmd(0x1E);

    	for (delay = 0 ; delay < 1000000 ; delay++);

    }

    for (delay = 0 ; delay < 8000000 ; delay++);

    Lcd_Imlec(2,1);
    Lcd_Yaz("Berkay Bostan");

    for(i=0; i<40; i++){

    	Lcd_Cmd(0x1E);

    	for (delay = 0 ; delay < 1000000 ; delay++);

    }

    for (delay = 0 ; delay < 12000000 ; delay++);

    Lcd_Clean();
    GPIO_PORTE_DATA_R &= ~(0x08);

}

void islem4(){

	volatile unsigned long delay;

		GPIO_PORTE_DATA_R |= 0x10;
		GPIO_PORTE_DATA_R &= ~(0x02);
		GPIO_PORTE_DATA_R &= ~(0x04);
		GPIO_PORTE_DATA_R &= ~(0x08);

		for (delay = 0 ; delay < 1000000 ; delay++);


    SysCtlClockSet(
                    SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN);


    int i;

    Lcd_init();
    Lcd_Cmd(0x0C);

    Lcd_Imlec(1,16);
    Lcd_Yaz("Kocaeli Uni");

    for(i=0; i<55; i++){

    	Lcd_Cmd(0x18);

        for (delay = 0 ; delay < 1000000 ; delay++);

    }

    for (delay = 0 ; delay < 8000000 ; delay++);

        Lcd_Imlec(2,16);
        Lcd_Yaz("Berkay Bostan");

    for(i=0; i<40; i++){

        Lcd_Cmd(0x18);

        for (delay = 0 ; delay < 1000000 ; delay++);

    }

    for (delay = 0 ; delay < 12000000 ; delay++);

    Lcd_Clean();
    GPIO_PORTE_DATA_R &= ~(0x10);

}

int main() {

	volatile unsigned long delay;

	init_port_E();

    while(1){

        int sayi=rand()%4;

        if(sayi==0){

        	islem1();

        	for (delay = 0 ; delay < 4000000 ; delay++);
        }

        if(sayi==1){

        	islem2();

        	for (delay = 0 ; delay < 4000000 ; delay++);
        }

        if(sayi==2){

        	islem3();

        	for (delay = 0 ; delay < 4000000 ; delay++);
        }

        if(sayi==3){

        	islem4();

        	for (delay = 0 ; delay < 4000000 ; delay++);
        }

	}
}
