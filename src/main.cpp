#include <Arduino.h>
#include "config.h"
#include "core/data_model.h"
#include "core/display_manager.h"
#include "core/button_fsm.h"

#ifdef BOARD_ESP32
#include "hal/esp32/hal_esp32.h"
static HalEsp32 hal;
#endif

static DisplayManager display;
static ButtonFSM      button(PIN_BUTTON);
static UsageData      usage = {};

void setup() {
    Serial.begin(SERIAL_BAUD);
    button.begin();
    hal.begin();
    hal.startBLE(BLE_DEVICE_NAME);
    display.begin(LCD_I2C_ADDR, LCD_COLS, LCD_ROWS);
    display.showScreen(SCREEN_STATUS);
}

void loop() {
    hal.poll();
    button.update();

    if (button.wasPressed()) {
        display.nextScreen();
    }

    if (hal.receivedData(usage)) {
        display.update(usage);
    }
}
