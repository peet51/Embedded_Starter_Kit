
#ifndef TM_RNG_H
#define TM_RNG_H 110
/**
 * @addtogroup TM_STM32F4xx_Libraries
 * @{
 */

/**
 * @defgroup TM_RNG
 * @brief    Random number generator library for STM32F4xx devices - http://stm32f4-discovery.com/2014/07/library-22-true-random-number-generator-stm32f4xx/
 * @{
 *
 * \par Changelog
 *
@verbatim
 Version 1.1
  - March 10, 2015
  - Added support for STD/HAL drivers
  
 Version 1.0
  - First release
@endverbatim
 *
 * \par Dependencies
 *
@verbatim
 - STM32F4xx
 - defines.h
@endverbatim
 */
#include "stm32f4xx.h"
#include "defines.h"

#ifndef RNG_NVIC_PREEMPTION_PRIORITY
#define RNG_NVIC_PREEMPTION_PRIORITY   0x02
#endif

#ifndef RNG_NVIC_SUBPRIORITY
#define RNG_NVIC_SUBPRIORITY           0x00
#endif

/**
 * @defgroup TM_RNG_Functions
 * @brief    Library Functions
 * @{
 */

/**
 * @brief  Initializes RNG peripheral and enables clock
 * @param  None
 * @retval None
 */
void TM_RNG_Init(void);

/**
 * @brief  De initializes RNG peripheral and disables clock
 * @param  None
 * @retval None
 */
void TM_RNG_DeInit(void);

/**
 * @brief  Gets 32-bit random number
 * @param  None
 * @retval 32-bit random number
 */
uint32_t TM_RNG_Get(void);

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

#endif

