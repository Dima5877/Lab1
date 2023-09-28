#include "header.h"
#include <zephyr.h>
#include "drivers/gpio.h"


void myFunc(const struct device *dev, bool *led_is_on, gpio_pin_t PIN)
{
    gpio_pin_set(dev, PIN, (int)*led_is_on);  //test this by gpio_pin_set(dev, PIN, 0);
	*led_is_on = !*led_is_on;
	k_msleep(2000);
}