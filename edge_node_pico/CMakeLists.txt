cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(sentinel_edge_node C CXX ASM)
pico_sdk_init()

add_executable(sentinel_edge_node
    src/main.c
    src/sensor_mpu6050.c
)

# Link the required hardware libraries
target_link_libraries(sentinel_edge_node pico_stdlib hardware_i2c hardware_uart)

# Create map/bin/hex/uf2 file
pico_add_extra_outputs(sentinel_edge_node)