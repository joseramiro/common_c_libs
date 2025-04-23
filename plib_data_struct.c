#include <xc.h>
#include "plib_data_struct.h"

/**
 * @file plib_data_struct.c
 * @brief Définitions types de données et fonctions de manipulation
 * @author Ramiro Najera
 * @version 1.0.0
 * @date 2025-04-23
 */

void Utils_Set_16bits_Flag(unsigned int *variable, unsigned char index)
{
    *variable |= (1 << index);
}

void Utils_Clear_16bits_Flag(unsigned int *variable, unsigned char index)
{
    *variable &= ~(1 << index);
}

unsigned char Utils_Check_16bits_Flag(unsigned int variable, int index)
{
    return (variable & (1 << index)) != 0;
}

unsigned char Utils_Calculate_CRC8_Raw(unsigned char* buffer, unsigned char size)
{
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < size; i++)
    {
        crc ^= buffer[i];
        for (j = 0; j < 8; j++)
        {
            if (crc & 0x80)
                crc = (uint8_t)((crc << 1) ^ 0x32);
            else
                crc <<= 1;
        }
    }
    return crc;
}

unsigned char Utils_Check_In_Range(unsigned int value, unsigned int setpoint, unsigned int tolerance)
{
    // Calculate thresholds and set 0 if minimum negative
    float setpointF = setpoint;
    float maxThreshold = (setpointF + tolerance);
    float minThreshold = (setpointF - tolerance);
    if(minThreshold < 0)
        minThreshold = 0;
    // Value is already in range: Nothing to be done
    if(value >= minThreshold && value <= maxThreshold)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}