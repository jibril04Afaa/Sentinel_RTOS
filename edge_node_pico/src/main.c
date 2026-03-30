#include <stdio.h>
#include "pico/stdlib.h"
#include "sensor_mpu6050.h"

#define PANIC_BUTTON_PIN 15
#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5

int main() {
    // Initialize standard I/O (routes stdout to UART0 by default on Pico)
    stdio_init_all();

    // Initialize Panic Button
    gpio_init(PANIC_BUTTON_PIN);
    gpio_set_dir(PANIC_BUTTON_PIN, GPIO_IN);
    gpio_pull_up(PANIC_BUTTON_PIN);

    // Initialize Sensor
    mpu6050_init(I2C_PORT, SDA_PIN, SCL_PIN);

    while (1) {
        float magnitude = mpu6050_get_magnitude(I2C_PORT);
        int button_pressed = !gpio_get(PANIC_BUTTON_PIN); // Invert because pull-up

        // The Heartbeat Packet: Format [M:value,B:value]
        printf("[M:%.2f,B:%d]\n", magnitude, button_pressed);

        sleep_ms(100); // 10Hz sampling rate
    }
}