#include <stdint.h>
#include "gpio.h"
#include "keypad.h"

int main(void) {
  struct gpio_t *d = (struct gpio_t*)GPIO_D;
  app_init(d);

  while (1) {
    out7seg(d, keyb(d));
  }  
}
