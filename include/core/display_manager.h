#pragma once
#include "data_model.h"
#include <LiquidCrystal_I2C.h>

enum Screen {
    SCREEN_STATUS,    // connection state + model name
    SCREEN_SESSION,   // session tokens + cost
    SCREEN_DAILY,     // daily tokens + cost
    SCREEN_COUNT      // sentinel — do not use as a screen value
};

class DisplayManager {
public:
    void   begin(uint8_t addr, uint8_t cols, uint8_t rows);
    void   showScreen(Screen s);
    void   nextScreen();
    void   update(const UsageData& data);

private:
    LiquidCrystal_I2C _lcd{0x27, 16, 2};
    Screen            _current = SCREEN_STATUS;
    UsageData         _last    = {};

    void renderStatus(const UsageData& d);
    void renderSession(const UsageData& d);
    void renderDaily(const UsageData& d);
};
