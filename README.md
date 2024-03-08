# Generic Shift Register Driver

Generic, portable, multi-instance shift register driver.

## Overview

This HAL-mediated custom shift register driver permits ease of use that is portable across many platforms.

## Usage

The shift register header and source rely on an external user-defined hardware abstraction layer (HAL) called `hal.h` which defines the necessary calls in the `HAL` namespace. Namely, a GPIO pin object with `pinMode()` and `digitalWrite()` methods, and a SPI bus object with a `transfer()` method.

The HAL GPIO pin object `pinMode()` method should set as output when supplied with a const value `GPIO_OUTPUT`. The `transfer()` method of the HAL SPI bus should clock out the `uint8_t` value supplied in its argument to the input clock and data pins of the shift register.

### Example

```cpp
#include <shift-register.h>

...

// Instantiate SPI bus
HAL::SPI spi_bus;

// Instantiate shift register
PeripheralIO::ShiftRegister shiftreg(spi_bus, PIN_A1);

...

int main()
{
    uint8_t some_data;

...
    // Init SPI bus (as appropriate)
    spi_bus.init();

    // Init shift register
    shiftreg.init();

...
    // Update shift register on condition
    if (someCondition)
    {
        shiftreg.write(some_data);
    }

...

}

...
```

## License

MIT © 2024 John Greenwell