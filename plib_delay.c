/**
 * @file plib_delay.c
 * @brief Définitions des fonctions de délai
 * @author Ramiro Najera
 * @version 1.0.1
 * @date 2025-04-23
 */

#include <xc.h>
#include "plib_delay.h"

void Wait_100ns(unsigned long ns100)
{
    unsigned long i = 0;
    for (i = 0; i < ns100; i++)
    {
        asm("nop");
    }
}

void Utils_Delay_Us(unsigned long us)
{
    unsigned long i = 0, j = 0;
    for (i = 0; i < us; i++)
    {
        for (j = 0; j < 10; j++)
        {
            asm("nop");
        }
    }
}

void Utils_Delay_Ms(unsigned long ms)
{
    unsigned long i = 0, j = 0;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            asm("nop");
        }
    }
}

unsigned int Utils_Reset_PIC()
{
    /* Perform a system unlock sequence */
    SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
    SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
    /* Set SWRST bit to arm reset */
    RSWRSTSET = 1;
    /* Read RSWRST register to trigger reset */
    unsigned int dummy;
    dummy = RSWRST;
    /* Prevent any unwanted code execution until reset occurs*/
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // Return dummy to avoid compilation warning
    return dummy;
}