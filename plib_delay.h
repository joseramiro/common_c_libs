#ifndef PLIB_DELAY_H
#define PLIB_DELAY_H

/**
 * @file plib_delay.h
 * @brief Définitions des fonctions de délai
 * @author Ramiro Najera
 * @version 1.0.1
 * @date 2025-04-23
 */

/**
 * @brief Fonction de délai en 100 ns
 * @param ns100 100 ns d'attente
 */
void Wait_100ns(unsigned long ns100);

/**
 * @brief Fonction de délai en µs
 * @param us µs d'attente
 */
void Utils_Delay_Us(unsigned long us);

/**
 * @brief Fonction de délai en ms
 * @param ms ms d'attente
 */
void Utils_Delay_Ms(unsigned long ms);

/**
 * @brief Fonction pour rédemarrer PIC
 * unsigned int Lecture de registre reset
 */
unsigned int Utils_Reset_PIC();

#endif  // PLIB_DELAY_H