#ifndef __SOFT_SPI_H__
#define __SOFT_SPI_H__
#include "driver/gpio.h"

#define CS_PIN        4
#define CS_PIN_SEL    (1ULL<<CS_PIN)
#define CLK_PIN       5
#define CLK_PIN_SEL   (1ULL<<CLK_PIN)
#define DIN_PIN       6
#define DIN_PIN_SEL   (1ULL<<DIN_PIN)
#define DOUT_PIN      7
#define DOUT_PIN_SEL  (1ULL<<DOUT_PIN)

#define CS1           gpio_set_level(CS_PIN, 1)
#define CS0           gpio_set_level(CS_PIN, 0)
#define CLK1          gpio_set_level(CLK_PIN, 1)                         
#define CLK0          gpio_set_level(CLK_PIN, 0)
#define DOUT1         gpio_set_level(DOUT_PIN, 1)
#define DOUT0         gpio_set_level(DOUT_PIN, 0)
#define DIN           gpio_get_level(DIN_PIN)

void soft_spi_init(void);
void spi_write_byte(uint8_t TxData);
uint8_t spi_recive_byte(void);

#endif
