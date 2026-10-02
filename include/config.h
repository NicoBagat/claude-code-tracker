#pragma once

// ── Display ───────────────────────────────────────────────────────────────────
#define LCD_I2C_ADDR  0x27   // common default; try 0x3F if display is blank
#define LCD_COLS      16
#define LCD_ROWS       2

// I2C pins (ESP32 Arduino defaults)
#define PIN_SDA       21
#define PIN_SCL       22

// ── Button ────────────────────────────────────────────────────────────────────
#define PIN_BUTTON     4     // adjust to suit breadboard wiring
#define BUTTON_DEBOUNCE_MS  50

// ── BLE ───────────────────────────────────────────────────────────────────────
#define BLE_DEVICE_NAME  "CC-Tracker"

// Generate stable UUIDs once and keep them here.
// These are placeholders — replace before first BLE pairing.
#define BLE_SERVICE_UUID       "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define BLE_CHAR_SESSION_UUID  "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define BLE_CHAR_DAILY_UUID    "beb5483e-36e1-4688-b7f5-ea07361b26a9"
#define BLE_CHAR_COST_UUID     "beb5483e-36e1-4688-b7f5-ea07361b26aa"
#define BLE_CHAR_STATUS_UUID   "beb5483e-36e1-4688-b7f5-ea07361b26ab"

// ── Serial fallback ───────────────────────────────────────────────────────────
#define SERIAL_BAUD   115200
