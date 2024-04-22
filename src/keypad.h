#pragma once

#include "gpio.h"

void app_init(struct gpio_t*);
unsigned char keyb(struct gpio_t*);
void out7seg(struct gpio_t*, unsigned char);
