#pragma once
#include <Arduino.h>

// Debounced button with single-press detection.
class ButtonFSM {
public:
    explicit ButtonFSM(uint8_t pin) : _pin(pin) {}
    void begin();
    void update();          // call every loop iteration
    bool wasPressed();      // true once per physical press; clears on read

private:
    uint8_t  _pin;
    bool     _lastState  = HIGH;
    bool     _pressed    = false;
    uint32_t _lastChange = 0;
};
