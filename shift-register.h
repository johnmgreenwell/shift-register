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
         * @param spi_bus Reference to SPI bus used for shift register
         * @param cs_pin Pin number connected to select/latch clock input on the shift register
        */
        ShiftRegister(HAL::SPI& spi_bus, uint8_t cs_pin);
        
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
        HAL::SPI& _spi;
        HAL::GPIO _cs_pin;
};

}

#endif // _SHIFT_REGISTER_H

// EOF
