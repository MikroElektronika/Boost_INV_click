_systemInit:
;Click_Boost_INV_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Boost_INV_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Boost_INV_STM.c,37 :: 		mikrobus_i2cInit( _MIKROBUS1, &_BOOSTINV_I2C_CFG[0] );
MOVW	R0, #lo_addr(__BOOSTINV_I2C_CFG+0)
MOVT	R0, #hi_addr(__BOOSTINV_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Boost_INV_STM.c,38 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Boost_INV_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Boost_INV_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Boost_INV_STM.c,43 :: 		boostinv_i2cDriverInit( (T_BOOSTINV_P)&_MIKROBUS1_GPIO, (T_BOOSTINV_P)&_MIKROBUS1_I2C, 0x31 );
MOVS	R2, #49
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_boostinv_i2cDriverInit+0
;Click_Boost_INV_STM.c,44 :: 		boostinv_enable();
BL	_boostinv_enable+0
;Click_Boost_INV_STM.c,46 :: 		_BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT |
MOVS	R0, __BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT
ORR	R0, R0, __BOOSTINV_CMD_REGISTER_SELECT_NEG_VOUT
UXTB	R0, R0
;Click_Boost_INV_STM.c,47 :: 		_BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
ORR	R0, R0, __BOOSTINV_CMD_REGISTER_SELECT_CONFIG
UXTB	R1, R0
;Click_Boost_INV_STM.c,45 :: 		boostinv_writeByte(_BOOSTINV_REG_COMMAND, _BOOSTINV_CMD_REGISTER_SELECT_POS_VOUT |
MOVS	R0, __BOOSTINV_REG_COMMAND
;Click_Boost_INV_STM.c,47 :: 		_BOOSTINV_CMD_REGISTER_SELECT_CONFIG );
BL	_boostinv_writeByte+0
;Click_Boost_INV_STM.c,48 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Boost_INV_STM.c,50 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Boost_INV_STM.c,53 :: 		Positive_Vout = 3200;
MOVW	R1, #3200
MOVW	R0, #lo_addr(_Positive_Vout+0)
MOVT	R0, #hi_addr(_Positive_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,54 :: 		boostinv_setPositiveVoltage(Positive_Vout);
MOVW	R0, #3200
BL	_boostinv_setPositiveVoltage+0
;Click_Boost_INV_STM.c,55 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_Boost_INV_STM.c,56 :: 		Positive_Vout = 7750;
MOVW	R1, #7750
MOVW	R0, #lo_addr(_Positive_Vout+0)
MOVT	R0, #hi_addr(_Positive_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,57 :: 		boostinv_setPositiveVoltage(Positive_Vout);
MOVW	R0, #7750
BL	_boostinv_setPositiveVoltage+0
;Click_Boost_INV_STM.c,58 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask4:
SUBS	R7, R7, #1
BNE	L_applicationTask4
NOP
NOP
NOP
;Click_Boost_INV_STM.c,59 :: 		Positive_Vout = 12000;
MOVW	R1, #12000
MOVW	R0, #lo_addr(_Positive_Vout+0)
MOVT	R0, #hi_addr(_Positive_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,60 :: 		boostinv_setPositiveVoltage(Positive_Vout);
MOVW	R0, #12000
BL	_boostinv_setPositiveVoltage+0
;Click_Boost_INV_STM.c,61 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;Click_Boost_INV_STM.c,62 :: 		Positive_Vout = 7750;
MOVW	R1, #7750
MOVW	R0, #lo_addr(_Positive_Vout+0)
MOVT	R0, #hi_addr(_Positive_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,63 :: 		boostinv_setPositiveVoltage(Positive_Vout);
MOVW	R0, #7750
BL	_boostinv_setPositiveVoltage+0
;Click_Boost_INV_STM.c,64 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask8:
SUBS	R7, R7, #1
BNE	L_applicationTask8
NOP
NOP
NOP
;Click_Boost_INV_STM.c,66 :: 		Negative_Vout = -1450;
MOVW	R1, #64086
SXTH	R1, R1
MOVW	R0, #lo_addr(_Negative_Vout+0)
MOVT	R0, #hi_addr(_Negative_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,67 :: 		boostinv_setNegativeVoltage(Negative_Vout);
MOVW	R0, #64086
SXTH	R0, R0
BL	_boostinv_setNegativeVoltage+0
;Click_Boost_INV_STM.c,68 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask10:
SUBS	R7, R7, #1
BNE	L_applicationTask10
NOP
NOP
NOP
;Click_Boost_INV_STM.c,69 :: 		Negative_Vout = -6700;
MOVW	R1, #58836
SXTH	R1, R1
MOVW	R0, #lo_addr(_Negative_Vout+0)
MOVT	R0, #hi_addr(_Negative_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,70 :: 		boostinv_setNegativeVoltage(Negative_Vout);
MOVW	R0, #58836
SXTH	R0, R0
BL	_boostinv_setNegativeVoltage+0
;Click_Boost_INV_STM.c,71 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask12:
SUBS	R7, R7, #1
BNE	L_applicationTask12
NOP
NOP
NOP
;Click_Boost_INV_STM.c,72 :: 		Negative_Vout = -11050;
MOVW	R1, #54486
SXTH	R1, R1
MOVW	R0, #lo_addr(_Negative_Vout+0)
MOVT	R0, #hi_addr(_Negative_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,73 :: 		boostinv_setNegativeVoltage(Negative_Vout);
MOVW	R0, #54486
SXTH	R0, R0
BL	_boostinv_setNegativeVoltage+0
;Click_Boost_INV_STM.c,74 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask14:
SUBS	R7, R7, #1
BNE	L_applicationTask14
NOP
NOP
NOP
;Click_Boost_INV_STM.c,75 :: 		Negative_Vout = -6700;
MOVW	R1, #58836
SXTH	R1, R1
MOVW	R0, #lo_addr(_Negative_Vout+0)
MOVT	R0, #hi_addr(_Negative_Vout+0)
STRH	R1, [R0, #0]
;Click_Boost_INV_STM.c,76 :: 		boostinv_setNegativeVoltage(Negative_Vout);
MOVW	R0, #58836
SXTH	R0, R0
BL	_boostinv_setNegativeVoltage+0
;Click_Boost_INV_STM.c,77 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask16:
SUBS	R7, R7, #1
BNE	L_applicationTask16
NOP
NOP
NOP
;Click_Boost_INV_STM.c,78 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Boost_INV_STM.c,80 :: 		void main()
;Click_Boost_INV_STM.c,82 :: 		systemInit();
BL	_systemInit+0
;Click_Boost_INV_STM.c,83 :: 		applicationInit();
BL	_applicationInit+0
;Click_Boost_INV_STM.c,85 :: 		while (1)
L_main18:
;Click_Boost_INV_STM.c,87 :: 		applicationTask();
BL	_applicationTask+0
;Click_Boost_INV_STM.c,88 :: 		}
IT	AL
BAL	L_main18
;Click_Boost_INV_STM.c,89 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
