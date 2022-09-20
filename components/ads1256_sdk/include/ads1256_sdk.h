#ifndef __ADS1256_SDK_H__
#define __ADS1256_SDK_H__
#include "driver/gpio.h"

#define RESET_PIN     2
#define RESET_PIN_SEL (1ULL<<RESET_PIN)
#define DRDY_PIN      3
#define DRDY_PIN_SEL (1ULL<<DRDY_PIN)

#define RESET1         gpio_set_level(RESET_PIN, 1)
#define RESET0         gpio_set_level(RESET_PIN, 0)
#define DRDY           gpio_get_level(DRDY_PIN)

void ads1256_gpio_init(void);
void ads1256_init(void);
void write_reg(unsigned char regaddr,unsigned char databyte);
unsigned int ads1256_read_data(void);  


/*ADS1256寄存器地址*/
#define REG_STATUS  0x00 //状态寄存器
#define REG_MUX     0x01 //通道寄存器
#define REG_ADCON   0x02 //AD控制寄存器
#define REG_DRATE   0x03 //采样速率寄存器
#define REG_IO      0x04 //IO控制寄存器
#define REG_OFC0    0x05 //OFC校准寄存器:offset calibration
#define REG_OFC1    0x06 //OFC
#define REG_OFC2    0x07 //OFC
#define REG_FSC0    0x08 //FSC校准寄存器:full-scale calibration
#define REG_FSC1    0x09 //FSC
#define REG_FSC2    0x0A //FSC
/*ADS1256寄存器命令*/
#define CMD_RDATA        0x01 //单次读取数据
#define CMD_RDATAC       0x03 //连续读取数据
#define CMD_SDATAC       0x0F //停止连续读取
#define CMD_RREG         0x10 //写寄存器
#define CMD_WREG         0x50 //读寄存器
#define CMD_SELFCAL      0xf0 //偏移增益自动校准
#define CMD_SELFOCAL     0xf1 //抵消自动校准
#define CMD_SELFGCAL     0xf2 //获取自动校准
#define CMD_SYSOCAL      0xf3 //系统偏移校准
#define CMD_SYSGCAL      0xf4 //系统增益校准
#define CMD_SYNC         0xfc //同步AD转换
#define CMD_STANDBY      0xfd //待机
#define CMD_WAKEUP       0x00 //唤醒
#define CMD_RESET        0xfe //复位
/*ADS1256放大器设置*/
#define PGA_1            0x00 //量程±5.000000V
#define PGA_2            0x01 //量程±2.500000V
#define PGA_4            0x02 //量程±1.250000V
#define PGA_8            0x03 //量程±0.625000V
#define PGA_16           0x04 //量程±0.312500V
#define PGA_32           0x05 //量程±0.156250V
#define PGA_64           0x06 //量程±0.078125V
/*ADS1256采样速率设置*/
#define DRATE_30000SPS   0xF0 //速率30000次/秒
#define DRATE_15000SPS   0xE0 //速率15000次/秒 
#define DRATE_7500SPS    0xD0 //速率7500次/秒 
#define DRATE_3750SPS    0xC0 //速率3750次/秒 
#define DRATE_2000SPS    0xB0 //速率2000次/秒 
#define DRATE_1000SPS    0xA1 //速率1000次/秒
#define DRATE_500SPS     0x92 //速率500次/秒 
#define DRATE_100SPS     0x82 //速率100次/秒 
#define DRATE_60SPS      0x72 //速率60次/秒 
#define DRATE_50SPS      0x63 //速率50次/秒 
#define DRATE_30SPS      0x53 //速率30次/秒 
#define DRATE_25SPS      0x43 //速率25次/秒 
#define DRATE_15SPS      0x33 //速率15次/秒 
#define DRATE_10SPS      0x23 //速率10次/秒 
#define DRATE_5SPS       0x13 //速率5次/秒 
#define DRATE_2SPS       0x03 //速率2次/秒
/*ADS1256复用器通道选择*/
#define MUXP_AIN0   0x00 //正极=AIN0
#define MUXP_AIN1   0x10 //正极=AIN1 
#define MUXP_AIN2   0x20 //正极=AIN2 
#define MUXP_AIN3   0x30 //正极=AIN3 
#define MUXP_AIN4   0x40 //正极=AIN4 
#define MUXP_AIN5   0x50 //正极=AIN5 
#define MUXP_AIN6   0x60 //正极=AIN6 
#define MUXP_AIN7   0x70 //正极=AIN7 
#define MUXP_AINCOM 0x80 //正极=ACOM 
#define MUXN_AIN0   0x00 //负极=AIN0
#define MUXN_AIN1   0x01 //负极=AIN1 
#define MUXN_AIN2   0x02 //负极=AIN2 
#define MUXN_AIN3   0x03 //负极=AIN3 
#define MUXN_AIN4   0x04 //负极=AIN4 
#define MUXN_AIN5   0x05 //负极=AIN5 
#define MUXN_AIN6   0x06 //负极=AIN6 
#define MUXN_AIN7   0x07 //负极=AIN7 
#define MUXN_AINCOM 0x08 //负极=ACOM  

#endif

