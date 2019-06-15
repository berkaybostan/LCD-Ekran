/*
 * Lcd.h
 *
 *  Created on: Apr 24, 2017
 *      Author: user
 */

#ifndef LCD_H_
#define LCD_H_

#define LCDPORT                  GPIO_PORTB_BASE
#define LCDPORTENABLE    SYSCTL_PERIPH_GPIOB
#define RS                               GPIO_PIN_0
#define E                                GPIO_PIN_1
#define D4                               GPIO_PIN_4
#define D5                               GPIO_PIN_5
#define D6                               GPIO_PIN_6
#define D7                               GPIO_PIN_7

void Lcd_Cmd(unsigned char);   //Lcd'ye komut gondermeye yarar
void Lcd_Clean(void);          //Lcd ekranini temizler
void Lcd_Yaz(char*);           //String ifade yazdirir
void Lcd_Imlec(char,char);     //İmleci istenilen yere gonderir
void Lcd_init(void);           //Lcd baslangic ayarlari
void Lcd_KarakterYaz(unsigned char);  //Tek karakter yazdirir

#endif /* LCD_H_ */
