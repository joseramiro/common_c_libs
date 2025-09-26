#ifndef PLIB_COMM_STRUCT_H
#define PLIB_COMM_STRUCT_H

/**
 * @file plib_comm_struct.h
 * @brief Définitions de structures pour communications
 * @author Ramiro Najera
 * @version 1.0.4
 * @date 2025-04-23
 */

/** 
 * @enum SPIChannel_t
 * @brief Numéros de channels de communication SPI
 */
typedef enum
{
    SPI_CH1 = 1,  /**< Channel SPI 1 */
    SPI_CH2 = 2   /**< Channel SPI 2 */
}SPIChannel_t;

/** 
 * @struct GPIO_t
 * @brief Structure de functions GPIO (set et reset)
 */
typedef struct 
{
    /** @brief Functions pour mettre à jour Chip Select à 1 */
    void(*set)(void);
    /** @brief Functions pour mettre à jour Chip Select à 0 */
    void(*clear)(void);
}GPIO_t;

/** 
 * @struct SPI_t
 * @brief Structure de configuration SPI
 */
typedef struct
{
    /** @brief Channel SPI @ref SPIChannel_t */
    unsigned char channel;  /**< Channel SPI */
    /** @brief Adresse SPI */
    unsigned char address;  /**< Adresse SPI */
    /** @brief Fonctions pour mettre à jour Chip Select */
    GPIO_t cs;
    /** @brief Fonctions pour mettre à jour Enable (Opto-coupler) */
    GPIO_t en;
}SPI_t;

#endif  // PLIB_COMM_STRUCT_H