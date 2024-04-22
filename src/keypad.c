#include "gpio.h"

void app_init(struct gpio_t *gpio) {
  // 15-12 ut, 11-8 in, 7-0 ut.
  gpio->moder = 0x55005555;
  gpio->otyper_h = 0x0F00;
  gpio->pupdr = 0x00AA0000;
  gpio->odrs.l = 0x3F;
}

void activate_row(struct gpio_t* gpio, uint8_t row) {
  gpio->odrs.h = 16 << (row - 1);
}

uint8_t read_col(struct gpio_t* gpio) {
  if (gpio->idrs.h & 1) {
    return 1;
  } else if (gpio->idrs.h & 2) {
    return 2;
  } else if (gpio->idrs.h & 4) {
    return 3;
  } else if (gpio->idrs.h & 8) {
    return 4;
  }
  return 0;
}

unsigned char key_value(uint8_t row, uint8_t col) {
  return (row-1) * 4 + col;
}
    

unsigned char keyb(struct gpio_t* gpio) {
  unsigned char k = 0xFF;
  for (uint8_t i = 1; i <= 4; i++) {
    activate_row(gpio, i);
    const uint8_t col = read_col(gpio);
    if (col) {
      k = key_value(i, col);
    }
  }
  return k;
}

void out7seg(struct gpio_t* gpio, unsigned char c) {
  const uint8_t segcodes[] = { 0x3F, 0x6, 0x5B, 0x4F,
			       0x66, 0x6D, 0x7D, 0x07,
			       0x7F, 0x6F, 0x77, 0x7F,
			       0x39, 0x3F, 0x79, 0x71};
  
  gpio->odrs.l = segcodes[c];
}
