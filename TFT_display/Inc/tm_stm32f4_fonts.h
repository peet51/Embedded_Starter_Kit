
#ifndef TM_FONTS_H
#define TM_FONTS_H 120

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup TM_STM32F4xx_Libraries
 * @{
 */

/**
 * @defgroup TM_FONTS
 * @brief    Fonts library for all my LCD libraries
 * @{
 *
 * Default fonts library. It is used in all LCD based libraries.
 *
 * \par Supported fonts
 * 
 * Currently, these fonts are supported:
 *  - 7 x 10 pixels
 *  - 11 x 18 pixels
 *  - 16 x 26 pixels
 *
 * \par Changelog
 *
@verbatim
 Version 1.2
  - May 24, 2015
  - Added support for string length and height
  
 Version 1.0
  - First release
@endverbatim
 *
 * \par Dependencies
 *
@verbatim
 - STM32F4xx
 - defines.h
 - string.h
@endverbatim
 */
#include "stm32f4xx.h"
#include "defines.h"
#include "string.h"

/**
 * @defgroup TM_LIB_Typedefs
 * @brief    Library Typedefs
 * @{
 */

/**
 * @brief  Font structure used on my LCD libraries
 */
typedef struct {
	uint8_t FontWidth;    /*!< Font width in pixels */
	uint8_t FontHeight;   /*!< Font height in pixels */
	const uint16_t *data; /*!< Pointer to data font data array */
} TM_FontDef_t;

/** 
 * @brief  String length and height 
 */
typedef struct {
	uint16_t Length;      /*!< String length in units of pixels */
	uint16_t Height;      /*!< String height in units of pixels */
} TM_FONTS_SIZE_t;

/**
 * @}
 */

/**
 * @defgroup TM_FONTS_FontVariables
 * @brief    Library font variables
 * @{
 */

/**
 * @brief  7 x 10 pixels font size structure 
 */
extern TM_FontDef_t TM_Font_7x10;

/**
 * @brief  11 x 18 pixels font size structure 
 */
extern TM_FontDef_t TM_Font_11x18;

/**
 * @brief  16 x 26 pixels font size structure 
 */
extern TM_FontDef_t TM_Font_16x26;

/**
 * @}
 */
 
/**
 * @defgroup TM_FONTS_Functions
 * @brief    Library functions
 * @{
 */

/**
 * @brief  Calculates string length and height in units of pixels depending on string and font used
 * @param  *str: String to be checked for length and height
 * @param  *SizeStruct: Pointer to empty @ref TM_FONTS_SIZE_t structure where informations will be saved
 * @param  *Font: Pointer to @ref TM_FontDef_t font used for calculations
 * @retval Pointer to string used for length and height
 */
char* TM_FONTS_GetStringSize(char* str, TM_FONTS_SIZE_t* SizeStruct, TM_FontDef_t* Font);

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

 
#endif

