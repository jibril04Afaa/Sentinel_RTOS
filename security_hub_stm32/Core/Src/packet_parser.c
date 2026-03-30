#include "packet_parser.h"
#include <stdio.h>
#include <string.h>

bool PacketParser_Decode(const char *raw_packet, SensorData_t *parsed_data_out) {
    if (raw_packet == NULL || parsed_data_out == NULL) {
        return false;
    }

    // Ensure the packet has the correct start and end boundaries
    if (raw_packet[0] != '[' || strchr(raw_packet, ']') == NULL) {
        return false; // Malformed packet
    }

    // Extract the values using sscanf. 
    // This expects exact format: "[M:%f,B:%d]"
    int parsed_items = sscanf(raw_packet, "[M:%f,B:%hhd]", 
                              &parsed_data_out->magnitude, 
                              &parsed_data_out->button_pressed);

    // If we didn't successfully extract exactly 2 items, the packet is junk
    if (parsed_items != 2) {
        return false; 
    }

    return true;
}