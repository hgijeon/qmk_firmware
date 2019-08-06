#pragma once

#include "pointing_device.h"
#include "quantum.h"
#include "report.h"
#include <util/delay.h>
#include "../../lib/lufa/LUFA/Drivers/Peripheral/SPI.h"

// Trackpad speed adjustments
#define POINTER_SPEED_MULTIPLIER 2
#define SCROLL_SPEED_DIVIDER 8

// Pins on corresponding ports
#define LVL_SHIFT_EN 7

// Configure as output
#define LVL_SHIFT_EN_INIT DDRC |= (1 << LVL_SHIFT_EN);

#define LVL_SHIFT_EN_HI PORTC |= (1 << LVL_SHIFT_EN);
#define LVL_SHIFT_EN_LO PORTC &= ~ (1 << LVL_SHIFT_EN);
