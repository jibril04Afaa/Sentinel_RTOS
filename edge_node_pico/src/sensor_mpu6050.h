#ifndef SENSOR_MPU6050_H
#define SENSOR_MPU6050_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

// MPU6050 Default I2C address
#define MPU6050_ADDR 0x68

void mpu6050_init(i2c_inst_t *i2c_port, uint sda_pin, uint scl_pin);
void mpu6050_read_accel(i2c_inst_t *i2c_port, float *accel_out);
float mpu6050_get_magnitude(i2c_inst_t *i2c_port);

#endif // SENSOR_MPU6050_H