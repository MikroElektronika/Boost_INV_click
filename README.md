![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Boost_INV Click

- **CIC Prefix**  : BOOSTINV
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : jul 2018.

---

### Software Support

We provide a library for the Boost_INV Click on our [LibStock](https://libstock.mikroe.com/projects/view/2495/boost-inv-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library initializes and defines I2C bus driver and driver functions which offer a choice to write data in registers and to read data from registers.
The library includes function for sets positive and negative output voltage and function for enable chip.
The user has to set a positive voltage from 3200mV to 12750mV with a step of 50mV 
and set the negative voltage from -1200mV to -13950mV with a step of 50mV.

Key functions :

- ``` void boostinv_setPositiveVoltage(uint16_t voltage) ``` - Functions for set positive output voltage
- ``` void boostinv_setNegativeVoltage(int16_t voltage) ``` - Functions for set negative output voltage
- ``` void boostinv_enable() ``` - Functions for enable chip

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module and sets RST pin as OUTPUT
- Application Initialization - Initializes Driver init, enable chip and select programing registers
- Application Task - (code snippet) - Changes the positive and negative output voltage.
                                      Positive output voltage goes from 3200mV to 12750mV with a step of 50mV
                                      Negative output voltage goes from -1200mV to -13950mV with a step of 50mV


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2495/boost-inv-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.


---
---
