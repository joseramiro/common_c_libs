#ifndef PLIB_DELAY_H
#define PLIB_DELAY_H

/**
 * @file plib_delay.h
 * @brief Définitions des fonctions de délai
 * @author Ramiro Najera
 * @version 1.0.5
 * @date 2025-04-23
 */

/**
 * @brief Fonction de délai en 100 ns
 * @param ns100 100 ns d'attente
 */
void Wait100ns(unsigned long ns100);

/**
 * @brief Fonction de délai en µs
 * @param us µs d'attente
 */
void Wait1us(unsigned long us);

/**
 * @brief Fonction pour rédemarrer PIC
 * @return unsigned int Lecture de registre reset
 */
unsigned int ResetPIC();

#endif  // PLIB_DELAY_H