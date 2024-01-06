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

ShiftRegister::ShiftRegister(uint8_t cs_pin, uint8_t spi_channel)
: _cs_pin(cs_pin)
, _spi(spi_channel)
{
    _cs_pin.pinMode(GPIO_OUTPUT);
    _cs_pin.digitalWrite(true);
}

void ShiftRegister::init() const
{
    _spi.init();
}

void ShiftRegister::write(uint8_t val) const
{
    _cs_pin.digitalWrite(false);
    _spi.transfer(val);
    _cs_pin.digitalWrite(true);
}

}

// EOF
