#include <stdio.h>
#include "ads1256_sdk.h"
#include "driver/gpio.h"
#include "soft-spi.h"
#include "esp32c3/rom/ets_sys.h"

void ads1256_gpio_init(void)
{
    gpio_config_t io_conf; 

    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;  
    io_conf.mode = GPIO_MODE_OUTPUT;       
    io_conf.pin_bit_mask = RESET_PIN_SEL;        
    io_conf.pull_down_en = 0;         
    io_conf.pull_up_en = 0;                     

    gpio_config(&io_conf); 

    io_conf.pin_bit_mask = DRDY_PIN_SEL;   
    io_conf.mode = GPIO_MODE_INPUT;             
    gpio_config(&io_conf);      

    gpio_set_level(RESET_PIN, 1);
    RESET1;
}

void write_reg(unsigned char regaddr,unsigned char databyte)
{
    CS0;
    while(DRDY);
    spi_write_byte(CMD_WREG | (regaddr & 0x0F));
    spi_write_byte(0x00);
    spi_write_byte(databyte);
    CS1;
}

void ads1256_init(void)
{
	write_reg(REG_STATUS,0x06);               
	write_reg(REG_ADCON,0x00);               
	write_reg(REG_DRATE,DRATE_1000SPS);  
	write_reg(REG_IO,0x00);  
}


unsigned int ads1256_read_data(void)  
{
    unsigned int sum=0;
	CS0;
	while(DRDY);           	
	spi_write_byte(CMD_SYNC);
	spi_write_byte(CMD_WAKEUP);	               
	spi_write_byte(CMD_RDATA);
    ets_delay_us(10);
    sum |= (spi_recive_byte()<<16);
	sum |= (spi_recive_byte()<< 8);
	sum |= spi_recive_byte();
    sum &= 0xfffe00;      
	CS1;
    return sum;
}


