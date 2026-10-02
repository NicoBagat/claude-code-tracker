#pragma once
#include <stdint.h>

// Canonical usage payload. Both BLE and serial paths deserialise into this.
struct UsageData {
    uint32_t session_tokens;
    uint32_t daily_tokens;
    float    session_cost_usd;
    float    daily_cost_usd;
    char     model[32];
    bool     connected;
    bool     fresh;          // true = data updated since last render; clear after display
};
