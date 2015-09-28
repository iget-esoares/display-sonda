/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    
    // Internal Reference ADC, only AN0 enabled as analog input
    ADCON1 = 0b00001110;
    
    // ADC Disabled with AN0 selected
    ADCON0 = 0b00000000;
    
    // ADC as 8TDA, Clock = Fosc / 8
    ADCON2 = 0b10100001;
    
    // ADC Enabled with AN0 selected
    ADCON0 = 0b00000001;
    
    // Disable AD Interrupt
    ADIE = 0;
    
    // Disable Interrupts
    GIE = 0;    
    
    // Only RA0 enabled as input (for AN)
    TRISA = 0b10000000;
    LATA = 0b00000000;
    
    // Entire PORTD as output
    TRISD = 0b00000000;
    LATD = 0b00000000;
    
}

