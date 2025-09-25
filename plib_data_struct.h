#ifndef PLIB_DATA_STRUCT_H
#define PLIB_DATA_STRUCT_H

/**
 * @file plib_data_struct.h
 * @brief Définitions types de données et fonctions de manipulation
 * @author Ramiro Najera
 * @version 1.0.2
 * @date 2025-04-23
 */

/** @brief Macro pour calculer taille de tableau */
#define SIZE_ARRAY(arr) (sizeof(arr) / sizeof((arr)[0]))
/** @brief Taille d'un char */
#define SIZE_CHAR       1
/** @brief Taille d'un int */
#define SIZE_INT        2
/** @brief Taille d'un long */
#define SIZE_LONG       4
/** @brief Taille d'un float */
#define SIZE_FLOAT      4

/** @brief Combine 2 bytes */
#define CONCAT(byte1, byte0) (((unsigned int)(byte1) << 8) + (byte0))
/** @brief Retourne le MSB d'un int */
#define GET_HIGH_BYTE(intValue) ((unsigned char)((intValue >> 8)))
/** @brief Retourne le LSB d'un int */
#define GET_LOW_BYTE(intValue) ((unsigned char)((intValue) & 0xFF))
/** @brief Met bit à 1 d'un flag */
#define SET_FLAG_BIT(flag, bit) ((flag) |= (1U << (bit)))
/** @brief Met bit à 0 d'un flag */
#define CLEAR_FLAG_BIT(flag, bit)  ((flag) &= ~(1U << (bit)))
/** @brief Retourne la valeur d'un bit d'un flag */
#define GET_FLAG_BIT(flag, bit)   (((flags >> (bit)) & 1U)

/** @brief Union pour manipuler des données entre float et chaine de char */
union FloatUsCharUnion
{
    /** @brief Valeur float */
    float floatValue;
    /** @brief Chaîne de char */
    unsigned char usChar[4];
};

/** @brief Union pour manipuler des données entre int et chaine de char */
union IntUsCharUnion
{
    /** @brief Valeur unsigned int */
    unsigned int usIntValue;
    /** @brief Valeur int */
    int IntValue;
    /** @brief Chaîne de char */
    unsigned char usChar[2];
};

/** @brief Union pour manipuler des données entre long et chaine de char */
union LongUsCharUnion
{
    /** @brief Valeur unsigned long */
    unsigned long usLongValue;
    /** @brief Valeur long */
    long longValue;
    /** @brief Valeur float */
    float floatValue;
    /** @brief Chaine de char */
    unsigned char usChar[4];
    /** @brief Chaine de int */
    unsigned int usInt[2];
};

/** @brief Union pour manipuler des données entre char et unsigned char */
union CharUsCharUnion
{
    /** @brief Valeur unsigned char */
    unsigned char usCharValue;
    /** @brief Valeur char */
    char charValue;
};

/**
 * @brief Calcule un CRC 8 bits
 * @param buffer Tableau de données
 * @param size Taille du tableau
 * @return unsigned char CRC
 */
unsigned char Utils_Calculate_CRC8_Raw(unsigned char* buffer, unsigned char size);

/**
 * @brief Vérifie si un numéro est dans une plage de données
 * @param value Valeur d'entrée
 * @param setpoint Valeur de consigne
 * @param tolerance Tolérance
 * @return unsigned char 1 si dans le plage, sinon 0
 */
unsigned char Utils_Check_In_Range(unsigned int value, unsigned int setpoint, unsigned int tolerance);

#endif  // PLIB_DATA_STRUCT_H