/*
    __boostinv_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __boostinv_driver.h
@brief    Boost_INV Driver
@mainpage Boost_INV Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BOOSTINV
@brief      Boost_INV Click Driver
@{

| Global Library Prefix | **BOOSTINV** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jul 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BOOSTINV_H_
#define _BOOSTINV_H_

/** 
 * @macro T_BOOSTINV_P
 * @brief Driver Abstract type 
 */
#define T_BOOSTINV_P    const uint8_t*

/** @defgroup BOOSTINV_COMPILE Compilation Config */              /** @{ */

//  #define   __BOOSTINV_DRV_SPI__                            /**<     @macro __BOOSTINV_DRV_SPI__  @brief SPI driver selector */
   #define   __BOOSTINV_DRV_I2C__                            /**<     @macro __BOOSTINV_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BOOSTINV_DRV_UART__                           /**<     @macro __BOOSTINV_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BOOSTINV_VAR Variables */                           /** @{ */

/* Register */
extern const uint8_t _BOOSTINV_REG_POSITIVE_VOUT;
extern const uint8_t _BOOSTINV_REG_NEGATIVE_VOUT;
extern const uint8_t _BOOSTINV_REG_CONFIG       ;
extern const uint8_t _BOOSTINV_REG_COMMAND      ;
extern const uint8_t _BOOSTINV_REG_OTP0         ;
extern const uint8_t _BOOSTINV_REG_OTP1         ;
extern const uint8_t _BOOSTINV_REG_OTP2         ;

 /* Configuration register */
extern const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_ENABLE      ;
extern const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_DISABLE     ;
extern const uint8_t _BOOSTINV_CFG_VPLUS_ENABLE            ;
extern const uint8_t _BOOSTINV_CFG_VPLUS_DISABLE           ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_1uA               ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_2uA               ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_4uA               ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_8uA               ;
extern const uint8_t _BOOSTINV_CFG_PDDIS_ENABLE            ;
extern const uint8_t _BOOSTINV_CFG_PDDIS_DISABLE           ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_OUTPUTS_DISABLED  ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTN_RAMP_1ST    ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST    ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_BOTH_RAMP_TOGETHER;
 
 /* Command register */
extern const uint8_t _BOOSTINV_CMD_WRITE_OTP_MEMORY        ;
extern const uint8_t _BOOSTINV_CMD_CLEAR_OTP_FAULT         ;
extern const uint8_t _BOOSTINV_CMD_RESET                   ;
extern const uint8_t _BOOSTINV_CMD_SWITCHES_OFF            ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_CONFIG  ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP2    ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP1    ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP0    ;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BOOSTINV_INIT Driver Initialization */              /** @{ */

#ifdef   __BOOSTINV_DRV_SPI__
void boostinv_spiDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P spiObj);
#endif
#ifdef   __BOOSTINV_DRV_I2C__
void boostinv_i2cDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P i2cObj, uint8_t slave);
#endif
#ifdef   __BOOSTINV_DRV_UART__
void boostinv_uartDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void boostinv_gpioDriverInit(T_BOOSTINV_P gpioObj);
                                                                       /** @} */
/** @defgroup BOOSTINV_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void boostinv_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] reg    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t boostinv_readByte(uint8_t reg);

/**
 * @brief Functions for enable chip
 */
void boostinv_enable();

/**
 * @brief Functions for set positive output voltage
 *
 * @param[in] voltage    Voltage that will be set
 *
 * Positive output voltage goes from 3200mV to 12750mV with a step of 50mV
 */
void boostinv_setPositiveVoltage(uint16_t voltage);

/**
 * @brief Functions for set negative output voltage
 *
 * @param[in] voltage    Voltage that will be set
 *
 * Negative output voltage goes from -1200mV to -13950mV with a step of 50mV
 */
void boostinv_setNegativeVoltage(int16_t voltage);


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Boost_INV_STM.c
    @example Click_Boost_INV_TIVA.c
    @example Click_Boost_INV_CEC.c
    @example Click_Boost_INV_KINETIS.c
    @example Click_Boost_INV_MSP.c
    @example Click_Boost_INV_PIC.c
    @example Click_Boost_INV_PIC32.c
    @example Click_Boost_INV_DSPIC.c
    @example Click_Boost_INV_AVR.c
    @example Click_Boost_INV_FT90x.c
    @example Click_Boost_INV_STM.mbas
    @example Click_Boost_INV_TIVA.mbas
    @example Click_Boost_INV_CEC.mbas
    @example Click_Boost_INV_KINETIS.mbas
    @example Click_Boost_INV_MSP.mbas
    @example Click_Boost_INV_PIC.mbas
    @example Click_Boost_INV_PIC32.mbas
    @example Click_Boost_INV_DSPIC.mbas
    @example Click_Boost_INV_AVR.mbas
    @example Click_Boost_INV_FT90x.mbas
    @example Click_Boost_INV_STM.mpas
    @example Click_Boost_INV_TIVA.mpas
    @example Click_Boost_INV_CEC.mpas
    @example Click_Boost_INV_KINETIS.mpas
    @example Click_Boost_INV_MSP.mpas
    @example Click_Boost_INV_PIC.mpas
    @example Click_Boost_INV_PIC32.mpas
    @example Click_Boost_INV_DSPIC.mpas
    @example Click_Boost_INV_AVR.mpas
    @example Click_Boost_INV_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __boostinv_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */