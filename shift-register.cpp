//--------------------------------------------------------------------------------------------------------------------
// Name        : shift-register.cpp
// Purpose     : Shift register driver class
// Description : This source file implements header file shift-register.h.
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
//--------------------------------------------------------------------------------------------------------------------

#include "shift-register.h"

namespace PeripheralIO
{

ShiftRegister::ShiftRegister(HAL::SPI& spi_bus, uint8_t cs_pin)
: _spi(spi_bus)
, _cs_pin(cs_pin)
{
    _cs_pin.pinMode(OUTPUT);
    _cs_pin.digitalWrite(true);
}

void ShiftRegister::init() const
{
    _cs_pin.pinMode(OUTPUT);
    _cs_pin.digitalWrite(true);
}

void ShiftRegister::write(uint8_t val) const
{
    _cs_pin.digitalWrite(false);
    _spi.transfer(val);
    _cs_pin.digitalWrite(true);
}

}

// EOF
