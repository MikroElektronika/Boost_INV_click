/*
Example for Boost_INV Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets RST pin as OUTPUT
- Application Initialization - Initializes Driver init, enable chip and select programing registers
- Application Task - (code snippet) - Changes the positive and negative output voltage.
                                      Positive output voltage goes from 3200mV to 12750mV with a step of 50mV
                                      Negative output voltage goes from -1200mV to -13950mV with a step of 50mV
*/

#include "Click_Boost_INV_types.h"
#include "Click_Boost_INV_config.h"

uint16_t Positive_Vout;
int16_t Negative_Vout;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_BOOSTINV_I2C_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    boostinv_i2cDriverInit( (T_BOOSTINV_P)&_MIKROBUS1_GPIO, (T_BOOSTINV_P)&_MIKROBUS1_I2C, 0x31 );
    boostinv_enable();
    boostinv_writeByte(_BOOSTINV_REG_CONFIG,_BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST);
    boostinv_writeByte(_BOOSTINV_REG_COMMAND, _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT |
                                              _BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT |
                                              _BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
}

void applicationTask()
{
// Sets Positive output voltage
    Positive_Vout = 3200;
    boostinv_setPositiveVoltage(Positive_Vout);
    Delay_ms( 5000 );
    Positive_Vout = 7750;
    boostinv_setPositiveVoltage(Positive_Vout);
    Delay_ms( 5000 );
    Positive_Vout = 12000;
    boostinv_setPositiveVoltage(Positive_Vout);
    Delay_ms( 5000 );
    Positive_Vout = 7750;
    boostinv_setPositiveVoltage(Positive_Vout);
    Delay_ms( 5000 );
// Sets Negative output voltage
    Negative_Vout = -1450;
    boostinv_setNegativeVoltage(Negative_Vout);
    Delay_ms( 5000 );
    Negative_Vout = -6700;
    boostinv_setNegativeVoltage(Negative_Vout);
    Delay_ms( 5000 );
    Negative_Vout = -11050;
    boostinv_setNegativeVoltage(Negative_Vout);
    Delay_ms( 5000 );
    Negative_Vout = -6700;
    boostinv_setNegativeVoltage(Negative_Vout);
    Delay_ms( 5000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}