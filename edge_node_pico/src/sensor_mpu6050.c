#include "sensor_mpu6050.h"
#include <math.h>

void mpu6050_init(i2c_inst_t *i2c_port, uint sda_pin, uint scl_pin) {
    i2c_init(i2c_port, 400 * 1000); // 400 kHz I2C
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);

    // Wake up MPU6050 (write 0 to power management register 0x6B)
    uint8_t buf[2] = {0x6B, 0x00};
    i2c_write_blocking(i2c_port, MPU6050_ADDR, buf, 2, false);
}

void mpu6050_read_accel(i2c_inst_t *i2c_port, float *accel_out) {
    uint8_t reg = 0x3B; // Start of accelerometer data registers
    uint8_t raw_data[6];
    
    i2c_write_blocking(i2c_port, MPU6050_ADDR, &reg, 1, true); 
    i2c_read_blocking(i2c_port, MPU6050_ADDR, raw_data, 6, false);

    // Convert raw 16-bit values
    int16_t x = (raw_data[0] << 8) | raw_data[1];
    int16_t y = (raw_data[2] << 8) | raw_data[3];
    int16_t z = (raw_data[4] << 8) | raw_data[5];

    // Assuming default +/- 2g range: divide by 16384.0 to get standard gravity (g)
    accel_out[0] = x / 16384.0f;
    accel_out[1] = y / 16384.0f;
    accel_out[2] = z / 16384.0f;
}

float mpu6050_get_magnitude(i2c_inst_t *i2c_port) {
    float accel[3];
    mpu6050_read_accel(i2c_port, accel);
    // Vector magnitude: sqrt(x^2 + y^2 + z^2)
    return sqrtf((accel[0]*accel[0]) + (accel[1]*accel[1]) + (accel[2]*accel[2]));
}