#include <stdio.h>
#include "soft-spi.h"
#include "driver/gpio.h"
#include "esp32c3/rom/ets_sys.h"

void soft_spi_init(void)
{
    gpio_config_t io_conf; 

    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;  
    io_conf.mode = GPIO_MODE_OUTPUT;       
    io_conf.pin_bit_mask = CS_PIN_SEL;        
    io_conf.pull_down_en = 0;         
    io_conf.pull_up_en = 0;                     
    gpio_config(&io_conf);  

    io_conf.pin_bit_mask = CLK_PIN_SEL; 
    gpio_config(&io_conf);   

    io_conf.pin_bit_mask = DOUT_PIN_SEL; 
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = DIN_PIN_SEL;   
    io_conf.mode = GPIO_MODE_INPUT;             
    gpio_config(&io_conf);
	CS1;
	CLK0;
	DOUT1;           
}

void spi_write_byte(uint8_t TxData)
{
	uint8_t i;
	ets_delay_us(1);
	for(i = 0; i < 8; i++)
	{
		if (TxData & 0x80)
		{
			DOUT1;
		}
		else
		{
			DOUT0;
		}
		CLK1;
		ets_delay_us(1);
		TxData <<= 1;
		CLK0;
		ets_delay_us(1);
	}
}

uint8_t spi_recive_byte(void)
{
	uint8_t i;
	uint8_t read = 0;
	ets_delay_us(1);
	for (i = 0; i < 8; i++)
	{
		CLK1;
		ets_delay_us(1);
		read = read<<1;
		CLK0;
		if (DIN)
		{
			read++;
		}
		ets_delay_us(1);
	}
	return read;
}
