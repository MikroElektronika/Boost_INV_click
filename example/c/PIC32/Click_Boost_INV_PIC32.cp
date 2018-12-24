#line 1 "D:/Clicks_git/B/Boost-INV_Click/SW/example/c/PIC32/Click_Boost_INV_PIC32.c"
#line 1 "d:/clicks_git/b/boost-inv_click/sw/example/c/pic32/click_boost_inv_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/b/boost-inv_click/sw/example/c/pic32/click_boost_inv_config.h"
#line 1 "d:/clicks_git/b/boost-inv_click/sw/example/c/pic32/click_boost_inv_types.h"
#line 3 "d:/clicks_git/b/boost-inv_click/sw/example/c/pic32/click_boost_inv_config.h"
const uint32_t _BOOSTINV_I2C_CFG[ 1 ] =
{
 400000
};
#line 1 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"
#line 58 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
extern const uint8_t _BOOSTINV_REG_POSITIVE_VOUT;
extern const uint8_t _BOOSTINV_REG_NEGATIVE_VOUT;
extern const uint8_t _BOOSTINV_REG_CONFIG ;
extern const uint8_t _BOOSTINV_REG_COMMAND ;
extern const uint8_t _BOOSTINV_REG_OTP0 ;
extern const uint8_t _BOOSTINV_REG_OTP1 ;
extern const uint8_t _BOOSTINV_REG_OTP2 ;


extern const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_ENABLE ;
extern const uint8_t _BOOSTINV_CFG_LOCKOUT_BIT_DISABLE ;
extern const uint8_t _BOOSTINV_CFG_VPLUS_ENABLE ;
extern const uint8_t _BOOSTINV_CFG_VPLUS_DISABLE ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_1uA ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_2uA ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_4uA ;
extern const uint8_t _BOOSTINV_CFG_IRAMP_8uA ;
extern const uint8_t _BOOSTINV_CFG_PDDIS_ENABLE ;
extern const uint8_t _BOOSTINV_CFG_PDDIS_DISABLE ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_OUTPUTS_DISABLED ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTN_RAMP_1ST ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST ;
extern const uint8_t _BOOSTINV_CFG_PUSEQ_BOTH_RAMP_TOGETHER;


extern const uint8_t _BOOSTINV_CMD_WRITE_OTP_MEMORY ;
extern const uint8_t _BOOSTINV_CMD_CLEAR_OTP_FAULT ;
extern const uint8_t _BOOSTINV_CMD_RESET ;
extern const uint8_t _BOOSTINV_CMD_SWITCHES_OFF ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_CONFIG ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP2 ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP1 ;
extern const uint8_t _BOOSTINV_CMD_REGISTER_SELECT_OTP0 ;
#line 106 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 113 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_gpioDriverInit( const uint8_t*  gpioObj);
#line 123 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_writeByte(uint8_t reg, uint8_t _data);
#line 131 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
uint8_t boostinv_readByte(uint8_t reg);
#line 136 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_enable();
#line 145 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_setPositiveVoltage(uint16_t voltage);
#line 154 "d:/clicks_git/b/boost-inv_click/sw/library/__boostinv_driver.h"
void boostinv_setNegativeVoltage(int16_t voltage);
#line 31 "D:/Clicks_git/B/Boost-INV_Click/SW/example/c/PIC32/Click_Boost_INV_PIC32.c"
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
 boostinv_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x31 );
 boostinv_enable();
 boostinv_writeByte(_BOOSTINV_REG_CONFIG,_BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST);
 boostinv_writeByte(_BOOSTINV_REG_COMMAND, _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT |
 _BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT |
 _BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
}

void applicationTask()
{

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
