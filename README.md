# claude-code-tracker

> Hardware peripheral that displays Claude Code usage stats on an LCD screen.

## Overview

A microcontroller-based device that connects to a PC running Claude Code, reads session usage data via a companion daemon, and renders the stats on an attached LCD display. Designed for desk use — wireless via BLE or tethered via USB-C.

## Hardware Targets

| Board | Connectivity | Status |
|---|---|---|
| ESP32 DevKit v1 | BLE + WiFi (native) | **Active target** |
| Arduino UNO R4 WiFi | BLE + WiFi (via ESP32-S3 coprocessor) | Deferred — HAL port |

**Peripherals:** I2C LCD (16x2 or 20x4 TBD), tactile button, LiPo battery + USB-C charging (prototype on breadboard)

## Tech Stack

- **Language:** C++ (Arduino framework)
- **Build system:** PlatformIO
- **Key libraries:** LiquidCrystal_I2C, ArduinoBLE / ESP32 BLE Arduino, USB CDC Serial

## Architecture

```
PC (Claude Code + companion daemon)
        │
        │  BLE (primary) / USB-C serial (fallback)
        ▼
MCU (UNO R4 WiFi or ESP32 DevKit v1)
        ├── LCD  — usage stats display
        └── Button  — cycle screens / refresh
```

## Getting Started

> Prerequisites and setup steps TBD during implementation phase.

## Project Structure

```
claude-code-tracker/
├── src/
│   ├── main.cpp
│   ├── core/               # board-agnostic logic
│   └── hal/esp32/          # ESP32 BLE + peripheral implementation
├── include/
│   ├── config.h            # pin defs, BLE UUIDs, display constants
│   ├── core/               # data_model, display_manager, button_fsm
│   └── hal/                # ihal.h interface + esp32/ implementation headers
├── lib/                    # vendored libraries
├── companion/              # PC-side daemon (Python, bleak)
└── platformio.ini          # esp32dev env active; uno_r4_wifi stub commented out
```

## Status

`active` — started 2026-05-21
