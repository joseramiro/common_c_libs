#ifndef PLIB_COMM_STRUCT_H
#define PLIB_COMM_STRUCT_H

typedef enum
{
    SPI_CH1 = 1,  /**< Channel SPI 1 */
    SPI_CH2 = 2   /**< Channel SPI 2 */
}PIC32SPIChannel;

typedef struct 
{
    void(*set)(void);    /**< Fonction qui met GPIO à 1 */
    void(*clear)(void);  /**< Fonction qui met GPIO à 0 */
}GPIOPin_t;

typedef struct
{
    unsigned char channel;  /**< Channel SPI */
    unsigned char address;  /**< Adresse SPI */
    GPIOPin_t cs;
}SPIConfiguration_t;

#endif  // PLIB_COMM_STRUCT_H