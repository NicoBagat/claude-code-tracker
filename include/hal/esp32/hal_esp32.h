#pragma once
#ifdef BOARD_ESP32

#include "hal/ihal.h"
#include <NimBLEDevice.h>

class HalEsp32 : public IHal, public NimBLEServerCallbacks, public NimBLECharacteristicCallbacks {
public:
    void begin()                        override;
    void startBLE(const char* name)     override;
    bool isClientConnected()            override;
    bool receivedData(UsageData& out)   override;
    void poll()                         override;

    // NimBLE callbacks
    void onConnect(NimBLEServer* s)     override;
    void onDisconnect(NimBLEServer* s)  override;
    void onWrite(NimBLECharacteristic* c) override;

private:
    NimBLEServer*         _server      = nullptr;
    NimBLECharacteristic* _charSession = nullptr;
    NimBLECharacteristic* _charDaily   = nullptr;
    NimBLECharacteristic* _charCost    = nullptr;
    NimBLECharacteristic* _charStatus  = nullptr;

    bool      _clientConnected = false;
    bool      _dataReady       = false;
    UsageData _pending         = {};
};

#endif // BOARD_ESP32
