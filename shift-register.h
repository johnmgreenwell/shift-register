//--------------------------------------------------------------------------------------------------------------------
// Name        : shift-register.h
// Purpose     : Shift register driver class
// Description : 
//               This driver class intended for control of 8-bit shift-register chips, such as the MC74HC595. These
//               chips are generally standardized to the extent that any deviation may be handled in the HAL.
//
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
// Requires    : External : N/A
//               Custom   : hal.h - Custom implementation-defined Hardware Abstraction Layer
//--------------------------------------------------------------------------------------------------------------------
#ifndef _SHIFT_REGISTER_H
#define _SHIFT_REGISTER_H

#include "hal.h"

namespace PeripheralIO
{

class ShiftRegister
{
    public:
        /**
         * @brief Constructor for ShiftRegister object
         * @param cs_pin Pin number connected to select/latch clock input on the shift register
         * @param spi_channel Identifier for HAL when more than one SPI channel is used
        */
        ShiftRegister(uint8_t cs_pin, uint8_t spi_channel=0);
        
        /**
         * @brief Initialize ShiftRegister object
        */
        void init() const;

        /**
         * @brief Shift and latch a value onto the shift register
         * @param val Value to be written
        */
        void write(uint8_t val) const;

    private:
        HAL::GPIO _cs_pin;
        HAL::SPI  _spi;
};

}

#endif // _SHIFT_REGISTER_H

// EOF
