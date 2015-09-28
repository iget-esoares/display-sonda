/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

#define DISPLAY_1_EN LATA = 0b00000010
#define DISPLAY_2_EN LATA = 0b00000100
#define DISPLAY_3_EN LATA = 0b00001000
#define DISPLAY_4_EN LATA = 0b00010000
#define _XTAL_FREQ = 8000000


unsigned int getDigitHex(unsigned int a)
{
    switch (a)
    {
        //               EDC BAFG
        case 1: return 0b00111000;
        
        //               EDC BAFG
        case 2: return 0b11011101;
        
        //               EDC BAFG
        case 3: return 0b01111101;
        
        //               EDC BAFG
        case 4: return 0b00111011;
        
        //               EDC BAFG
        case 5: return 0b01110111;
        
        //               EDC BAFG
        case 6: return 0b11110111;
        
        //               EDC BAFG
        case 7: return 0b00101100;
        
        //               EDC BAFG
        case 8: return 0b11111111;
        
        //               EDC BAFG
        case 9: return 0b01111111;
        
        //               EDC BAFG
        case 0: return 0b11111110;
    }
    
    return 0;
}

void main(void)
{
    unsigned int adc_read;
    unsigned char digit0, digit1, digit2;
    unsigned int aux;
    float lambda;
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    while(1)
    {
        // Start ADC conversion and wait for result
        GODONE = 1;
        while (GODONE) { };
        
        adc_read = (ADRESH << 8) | ADRESL;
        
        lambda = (0.77175 * adc_read) / 1023 + 0.55913;       
        
        aux = (int) ((lambda * 100) + 0.5f); // 097
        
        digit0 = (aux / 100); // 0
               
        digit1 = ((aux / 10) % 10);
        
        digit2 = (aux % 10);
        
        DISPLAY_2_EN;
        LATD = getDigitHex(digit0);
        
        _delay(20000);
        
        DISPLAY_3_EN;
        LATD = getDigitHex(digit1);
        _delay(20000);
        
        DISPLAY_4_EN;
        LATD = getDigitHex(digit2);
        _delay(20000);
    }

}
