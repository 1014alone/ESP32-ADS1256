/*
 * 时间:2022/8/5
 * 作者:曾伟豪
 * Website:http://117.50.186.104:1024/archives/ads1256esp32
*/

/*
	本历程使用的是模拟SPI驱动ADS1256
	详细说明请参考上述博客网址
	RESET  -->  GPIO2   若想修改引脚，请在ads1256_sdk.h中修改
	DRDY   -->  GPIO3   若想修改引脚，请在ads1256_sdk.h中修改
	CS     -->  GPIO4	若想修改引脚，请在soft-spi.h中修改	
	CLK    -->  GPIO5	若想修改引脚，请在soft-spi.h中修改
	DIN    -->  GPIO6	若想修改引脚，请在soft-spi.h中修改
	DOUT   -->  GPIO7	若想修改引脚，请在soft-spi.h中修改
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "soft-spi.h"
#include "ads1256_sdk.h"

void app_main(void)
{
	int i = 0;
    int ulResult;
	float ldVolutage[8];
    soft_spi_init();
    ads1256_gpio_init();
    ads1256_init();
    while (1) {
		for (i = 0; i < 8; i++)
		{
			switch(i){
				case 0: write_reg(REG_MUX,MUXP_AIN0|MUXN_AINCOM); break;      	//切换为采集通道1
				case 1: write_reg(REG_MUX,MUXP_AIN1|MUXN_AINCOM); break;	  	//切换为采集通道2
				case 2: write_reg(REG_MUX,MUXP_AIN2|MUXN_AINCOM); break;		//切换为采集通道3
				case 3: write_reg(REG_MUX,MUXP_AIN3|MUXN_AINCOM); break;		//切换为采集通道4
				case 4: write_reg(REG_MUX,MUXP_AIN4|MUXN_AINCOM); break;		//切换为采集通道5
				case 5: write_reg(REG_MUX,MUXP_AIN5|MUXN_AINCOM); break;		//切换为采集通道6
				case 6: write_reg(REG_MUX,MUXP_AIN6|MUXN_AINCOM); break;		//切换为采集通道7
				case 7: write_reg(REG_MUX,MUXP_AIN7|MUXN_AINCOM); break;		//切换为采集通道8
			}
			ulResult = ads1256_read_data();
			if( ulResult & 0x800000)
			{
				ulResult = ~ulResult;
				ulResult &= 0x7fffff;
				ulResult += 1;
				ulResult = -ulResult;
			}
			ldVolutage[i] = (ulResult*0.59604644775390625)/1000000.0;
		}
		printf("%.7f,%.7f,%.7f,%.7f,%.7f,%.7f,%.7f,%.7f\r\n",ldVolutage[0],ldVolutage[1],ldVolutage[2],ldVolutage[3],ldVolutage[4],ldVolutage[5],ldVolutage[6],ldVolutage[7]); 
		vTaskDelay(1);
    }
}
