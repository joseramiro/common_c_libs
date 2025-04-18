#ifndef PLIB_DELAY_H
#define PLIB_DELAY_H

/**
 * @brief Delay function in 100 nanoseconds
 * @param nanoseconds_100 100 nanoseconds to wait
 */
void Utils_Delay_100ns(unsigned long nanoseconds_100);

/**
 * @brief Delay function in microseconds
 * @param microseconds Microseconds to wait
 */
void Utils_Delay_Us(unsigned long microseconds);

/**
 * @brief Delay function in milliseconds
 * @param milliseconds Milliseconds to wait
 */
void Utils_Delay_Ms(unsigned long milliseconds);

unsigned int Utils_Reset_PIC();

#endif  // PLIB_DELAY_H