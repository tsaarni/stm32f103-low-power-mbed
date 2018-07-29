
#pragma once

// If your target does not have external clock, compile mbed with
// -DMBED_CONF_TARGET_LSE_AVAILABLE=0 to use internal clock


void enter_standy(uint8_t hours, uint8_t minutes, uint8_t seconds);
