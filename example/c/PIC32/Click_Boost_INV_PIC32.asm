_systemInit:
;Click_Boost_INV_PIC32.c,34 :: 		void systemInit()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_Boost_INV_PIC32.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
MOVZ	R27, R0, R0
ORI	R26, R0, 1
MOVZ	R25, R0, R0
JAL	_mikrobus_gpioInit+0
NOP	
;Click_Boost_INV_PIC32.c,37 :: 		mikrobus_i2cInit( _MIKROBUS1, &_BOOSTINV_I2C_CFG[0] );
LUI	R2, hi_addr(__BOOSTINV_I2C_CFG+0)
ORI	R2, R2, lo_addr(__BOOSTINV_I2C_CFG+0)
MOVZ	R26, R2, R0
MOVZ	R25, R0, R0
JAL	_mikrobus_i2cInit+0
NOP	
;Click_Boost_INV_PIC32.c,38 :: 		Delay_ms( 100 );
LUI	R24, 40
ORI	R24, R24, 45226
L_systemInit0:
ADDIU	R24, R24, -1
BNE	R24, R0, L_systemInit0
NOP	
;Click_Boost_INV_PIC32.c,39 :: 		}
L_end_systemInit:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _systemInit
_applicationInit:
;Click_Boost_INV_PIC32.c,41 :: 		void applicationInit()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_Boost_INV_PIC32.c,43 :: 		boostinv_i2cDriverInit( (T_BOOSTINV_P)&_MIKROBUS1_GPIO, (T_BOOSTINV_P)&_MIKROBUS1_I2C, 0x31 );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
ORI	R27, R0, 49
LUI	R26, hi_addr(__MIKROBUS1_I2C+0)
ORI	R26, R26, lo_addr(__MIKROBUS1_I2C+0)
LUI	R25, hi_addr(__MIKROBUS1_GPIO+0)
ORI	R25, R25, lo_addr(__MIKROBUS1_GPIO+0)
JAL	_boostinv_i2cDriverInit+0
NOP	
;Click_Boost_INV_PIC32.c,44 :: 		boostinv_enable();
JAL	_boostinv_enable+0
NOP	
;Click_Boost_INV_PIC32.c,45 :: 		boostinv_writeByte(_BOOSTINV_REG_CONFIG,_BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST);
ORI	R26, R0, __BOOSTINV_CFG_PUSEQ_VOUTP_RAMP_1ST
ORI	R25, R0, __BOOSTINV_REG_CONFIG
JAL	_boostinv_writeByte+0
NOP	
;Click_Boost_INV_PIC32.c,47 :: 		_BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT |
ORI	R2, R0, __BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT
ORI	R2, R2, __BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT
;Click_Boost_INV_PIC32.c,48 :: 		_BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
ORI	R2, R2, __BOOSTINV_CMD_REGISTER_SELECT_CONFIG
ANDI	R26, R2, 255
;Click_Boost_INV_PIC32.c,46 :: 		boostinv_writeByte(_BOOSTINV_REG_COMMAND, _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT |
ORI	R25, R0, __BOOSTINV_REG_COMMAND
;Click_Boost_INV_PIC32.c,48 :: 		_BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
JAL	_boostinv_writeByte+0
NOP	
;Click_Boost_INV_PIC32.c,49 :: 		}
L_end_applicationInit:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _applicationInit
_applicationTask:
;Click_Boost_INV_PIC32.c,51 :: 		void applicationTask()
ADDIU	SP, SP, -8
SW	RA, 0(SP)
;Click_Boost_INV_PIC32.c,54 :: 		Positive_Vout = 3200;
SW	R25, 4(SP)
ORI	R2, R0, 3200
SH	R2, Offset(_Positive_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,55 :: 		boostinv_setPositiveVoltage(Positive_Vout);
ORI	R25, R0, 3200
JAL	_boostinv_setPositiveVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,56 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask2:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask2
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,57 :: 		Positive_Vout = 7750;
ORI	R2, R0, 7750
SH	R2, Offset(_Positive_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,58 :: 		boostinv_setPositiveVoltage(Positive_Vout);
ORI	R25, R0, 7750
JAL	_boostinv_setPositiveVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,59 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask4:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask4
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,60 :: 		Positive_Vout = 12000;
ORI	R2, R0, 12000
SH	R2, Offset(_Positive_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,61 :: 		boostinv_setPositiveVoltage(Positive_Vout);
ORI	R25, R0, 12000
JAL	_boostinv_setPositiveVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,62 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask6:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask6
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,63 :: 		Positive_Vout = 7750;
ORI	R2, R0, 7750
SH	R2, Offset(_Positive_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,64 :: 		boostinv_setPositiveVoltage(Positive_Vout);
ORI	R25, R0, 7750
JAL	_boostinv_setPositiveVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,65 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask8:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask8
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,67 :: 		Negative_Vout = -1450;
ORI	R2, R0, 64086
SH	R2, Offset(_Negative_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,68 :: 		boostinv_setNegativeVoltage(Negative_Vout);
ORI	R25, R0, 64086
JAL	_boostinv_setNegativeVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,69 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask10:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask10
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,70 :: 		Negative_Vout = -6700;
ORI	R2, R0, 58836
SH	R2, Offset(_Negative_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,71 :: 		boostinv_setNegativeVoltage(Negative_Vout);
ORI	R25, R0, 58836
JAL	_boostinv_setNegativeVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,72 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask12:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask12
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,73 :: 		Negative_Vout = -11050;
ORI	R2, R0, 54486
SH	R2, Offset(_Negative_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,74 :: 		boostinv_setNegativeVoltage(Negative_Vout);
ORI	R25, R0, 54486
JAL	_boostinv_setNegativeVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,75 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask14:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask14
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,76 :: 		Negative_Vout = -6700;
ORI	R2, R0, 58836
SH	R2, Offset(_Negative_Vout+0)(GP)
;Click_Boost_INV_PIC32.c,77 :: 		boostinv_setNegativeVoltage(Negative_Vout);
ORI	R25, R0, 58836
JAL	_boostinv_setNegativeVoltage+0
NOP	
;Click_Boost_INV_PIC32.c,78 :: 		Delay_ms( 5000 );
LUI	R24, 2034
ORI	R24, R24, 33108
L_applicationTask16:
ADDIU	R24, R24, -1
BNE	R24, R0, L_applicationTask16
NOP	
NOP	
NOP	
;Click_Boost_INV_PIC32.c,79 :: 		}
L_end_applicationTask:
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 8
JR	RA
NOP	
; end of _applicationTask
_main:
;Click_Boost_INV_PIC32.c,81 :: 		void main()
;Click_Boost_INV_PIC32.c,83 :: 		systemInit();
JAL	_systemInit+0
NOP	
;Click_Boost_INV_PIC32.c,84 :: 		applicationInit();
JAL	_applicationInit+0
NOP	
;Click_Boost_INV_PIC32.c,86 :: 		while (1)
L_main18:
;Click_Boost_INV_PIC32.c,88 :: 		applicationTask();
JAL	_applicationTask+0
NOP	
;Click_Boost_INV_PIC32.c,89 :: 		}
J	L_main18
NOP	
;Click_Boost_INV_PIC32.c,90 :: 		}
L_end_main:
L__main_end_loop:
J	L__main_end_loop
NOP	
; end of _main
