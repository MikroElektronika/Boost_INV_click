/*
    __boostinv_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__boostinv_driver.h"
#include "__boostinv_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */
const uint8_t _BOOSTINV_REG_POSITIVE_VOUT = 0x00;
const uint8_t _BOOSTINV_REG_NEGATIVE_VOUT = 0x01;
const uint8_t _BOOSTINV_REG_CONFIG        = 0x02;
const uint8_t _BOOSTINV_REG_COMMAND       = 0x04;
const uint8_t _BOOSTINV_REG_OTP0          = 0x00;
const uint8_t _BOOSTINV_REG_OTP1          = 0x01;
const uint8_t _BOOSTINV_REG_OTP2          = 0x02;

/* Configuration register */
const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_ENABLE         = 0x40;
const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_DISABLE        = 0x00;
const uint8_t _BOOSTINV_CFG_VPLUS_ENABLE               = 0x20;
const uint8_t _BOOSTINV_CFG_VPLUS_DISABLE              = 0x00;
const uint8_t _BOOSTINV_CFG_IRAMP_1uA                  = 0x00;
const uint8_t _BOOSTINV_CFG_IRAMP_2uA                  = 0x08;
const uint8_t _BOOSTINV_CFG_IRAMP_4uA                  = 0x10;
const uint8_t _BOOSTINV_CFG_IRAMP_8uA                  = 0x18;
const uint8_t _BOOSTINV_CFG_PDDIS_ENABLE               = 0x04;
const uint8_t _BOOSTINV_CFG_PDDIS_DISABLE              = 0x00;
const uint8_t _BOOSTINV_CFG_PUSEQ_OUTPUTS_DISABLED     = 0x00;
const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTN_RAMP_1ST       = 0x01;
const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST       = 0x02;
const uint8_t _BOOSTINV_CFG_PUSEQ_BOTH_RAMP_TOGETHER   = 0x03;

/* Command register */
const uint8_t _BOOSTINV_CMD_WRITE_OTP_MEMORY         = 0x80;
const uint8_t _BOOSTINV_CMD_CLEAR_OTP_FAULT          = 0x40;
const uint8_t _BOOSTINV_CMD_RESET                    = 0x20;
const uint8_t _BOOSTINV_CMD_SWITCHES_OFF             = 0x10;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT = 0x04;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT = 0x02;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_CONFIG   = 0x01;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP2     = 0x00;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP1     = 0x00;
const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP0     = 0x00;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BOOSTINV_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BOOSTINV_DRV_SPI__

void boostinv_spiDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __BOOSTINV_DRV_I2C__

void boostinv_i2cDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __BOOSTINV_DRV_UART__

void boostinv_uartDriverInit(T_BOOSTINV_P gpioObj, T_BOOSTINV_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void boostinv_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];
    
    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t boostinv_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);
    
    return readReg[ 0 ];
}

void boostinv_enable()
{
    hal_gpio_rstSet(0);
    Delay_100ms();
    Delay_100ms();
    hal_gpio_rstSet(1);
    Delay_100ms();
}

void boostinv_setPositiveVoltage(uint16_t voltage)
{
    uint16_t Vp;
    uint16_t Vout;
    
    if(voltage < 3200)
    {
        Vout = 3200;
    }
    else if(voltage > 12750)
    {
        Vout = 12750;
    }
    else
    {
        Vout = voltage;
    }
    
    Vp = (Vout - 3200) / 50;
    boostinv_writeByte(0x00, Vp);
}

void boostinv_setNegativeVoltage(int16_t voltage)
{
    uint16_t Vn;
    int16_t Vout;
    
    if(voltage > -1200)
    {
        Vout = 1200;
    }
    else if( voltage < - 14000)
    {
        Vout = 13950;
    }
    else
    {
        Vout = - voltage;
    }
    
    Vn = ( Vout - 1200) / 50;
    boostinv_writeByte(0x01, Vn);
}

/* -------------------------------------------------------------------------- */
/*
  __boostinv_driver.c

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