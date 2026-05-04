#ifndef __MPU6050_H
#define __MPU6050_H

#include "ti_msp_dl_config.h"

// I2C引脚定义
#define SOFT_IIC_SCL_PORT GPIOA        // SCL端口
#define SOFT_IIC_SCL_PIN DL_GPIO_PIN_1 // SCL引脚
#define SOFT_IIC_SDA_PORT GPIOA        // SDA端口
#define SOFT_IIC_SDA_PIN DL_GPIO_PIN_0 // SDA引脚
#define MPU6050_SDA_input IOMUX_PINCM1 // SDA引脚IOMUX配置

// MPU6050寄存器地址定义
#define SMPLRT_DIV 0x19   // 采样率分频，典型值：0x07(125Hz) */
#define CONFIG 0x1A       // 低通滤波频率，典型值：0x06(5Hz) */
#define GYRO_CONFIG 0x1B  // 陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s) */
#define ACCEL_CONFIG 0x1C // 加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz) */

#define ACCEL_XOUT_H 0x3B // 存储最近的X轴、Y轴、Z轴加速度感应器的测量值 */
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define TEMP_OUT_H 0x41 // 存储的最近温度传感器的测量值 */
#define TEMP_OUT_L 0x42

#define GYRO_XOUT_H 0x43 // 存储最近的X轴、Y轴、Z轴陀螺仪感应器的测量值 */
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

#define PWR_MGMT_1 0x6B // 电源管理，典型值：0x00(正常启用) */
#define PWR_MGMT_2 0x6C // 电源管理，典型值：0x00(正常启用) */
#define WHO_AM_I 0x75   // IIC地址寄存器(默认数值0x68，只读) */

// HAL库的读写只需要使用7位地址
#define MPU6050_ADDR_AD0_LOW 0x68 // AD0低电平时7位地址为0X68 iic写时时发送0XD0
#define MPU6050_ADDR_AD0_HIGH 0x69

#define YAW_FILTER_WINDOW 4
#define YAW_DEADBAND     0.5f   // 死区阈值，需根据你的陀螺仪量纲调整


// 函数声明
void MPU6050_Init(void);
uint8_t MPU6050_GetDeviceID(void);
float MPU6050_GET_Tempure(void);
float MPU6050_GetAccelX(void);
float MPU6050_GetAccelY(void);
float MPU6050_GetAccelZ(void);
float MPU6050_GetGroX(void);
float MPU6050_GetGroY(void);
float MPU6050_GetGroZ(void);
float MPU6050Gyro_calibrate(void);
float MPU6050_Getyaw(void);


#endif /* __MPU6050_H */