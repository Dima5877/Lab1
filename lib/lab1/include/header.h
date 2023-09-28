#pragma once
#include <zephyr.h>
#include "drivers/gpio.h"


void myFunc(const struct device *dev, bool *led_is_on, gpio_pin_t PIN);