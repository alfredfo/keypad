#pragma once
#include <gpio-macros.h>

struct gpio_t {
  uint32_t moder;
  union {
    uint16_t otyper_h;
    uint32_t otyper;
  };
  uint32_t ospeedr;
  uint32_t pupdr;
  union {
    struct {
      uint8_t l;
      uint8_t h;
      uint16_t _padding00;
    }idrs;
    uint32_t idr;
  };
  union {
    struct {
      uint8_t l;
      uint8_t h;
      uint16_t _padding00;
    }odrs;
    uint32_t odr;
  };
  uint32_t bsrr;
  uint32_t lckr;
  uint32_t afrl;
  uint32_t afrh;
};
