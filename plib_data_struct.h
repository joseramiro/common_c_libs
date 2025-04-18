#ifndef PLIB_DATA_STRUCT_H
#define PLIB_DATA_STRUCT_H

/**
 * @brief Macro for size of array
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
/**
 * @brief Taille d'un char
 */
#define SIZE_CHAR       1
/**
 * @brief Taille d'un int
 */
#define SIZE_INT        2
/**
 * @brief Taille d'un long
 */
#define SIZE_LONG       4
/**
 * @brief Taille d'un float
 */
#define SIZE_FLOAT      4
/**
 * @brief Calcule un masque pour mettre à 1 un bit
 */
#define CALCULATE_SET_BINARY_MASK(decimalValue) ((1 << (decimalValue)) - 1)
/**
 * @brief Combine 2 bytes
 */
#define CONCAT_BYTES(byte1, byte0) (((unsigned int)(byte1) << 8) + (byte0))
/**
 * @brief Retourne le MSB d'un int
 */
#define GET_HIGH_BYTE(intValue) ((unsigned char)((intValue >> 8)))
/**
 * @brief Retourne le LSB d'un int
 */
#define GET_LOW_BYTE(intValue) ((unsigned char)((intValue) & 0xFF))


/**
 * @brief Union pour manipuler des données entre float et chaine de char
 */
union FloatUsCharUnion
{
    float floatValue;           /**< Valeur float */
    unsigned char usChar[4];    /**< Chaine de char */
};
/**
 * @brief Union pour manipuler des données entre int et chaine de char
 */
union IntUsCharUnion
{
    unsigned int usIntValue;     /**< Valuer unsigned int */
    int IntValue;                /**< Valeur int */
    unsigned char usChar[2];     /**< Chaine de char */
};
/**
 * @brief Union pour manipuler des données entre long et chaine de char
 * 
 */
union LongUsCharUnion
{
    unsigned long usLongValue;      /**< Valeur unsigned long */
    long longValue;                 /**< Valeur long */
    unsigned char usChar[4];        /**< Chaine de char */
    unsigned int usInt[2];          /**< Chaine de int */
};
/**
 * @brief Union pour manipuler des données entre char et unsigned char
 */
union CharUsCharUnion
{
    unsigned char usCharValue;      /**< Valeur unsigned char */
    char charValue;                 /**< Valeur char */
};

void Utils_Set_16bits_Flag(unsigned int *variable, unsigned char index);
void Utils_Clear_16bits_Flag(unsigned int *variable, unsigned char index);
unsigned char Utils_Check_16bits_Flag(unsigned int variable, int index);

unsigned char Utils_Calculate_CRC8_Raw(unsigned char* buffer, unsigned char size);

unsigned char Utils_Check_In_Range(unsigned int value, unsigned int setpoint, unsigned int tolerance);

#endif  // PLIB_DATA_STRUCT_H