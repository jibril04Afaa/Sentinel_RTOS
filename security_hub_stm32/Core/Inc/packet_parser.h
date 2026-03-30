#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H

#include "security_state.h"
#include <stdbool.h>

// Parses a string like "[M:1.05,B:0]" into the SensorData_t struct
// Returns true if successful, false if the packet was corrupted/invalid
bool PacketParser_Decode(const char *raw_packet, SensorData_t *parsed_data_out);

#endif // PACKET_PARSER_H