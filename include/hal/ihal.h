#pragma once
#include "core/data_model.h"

// Hardware abstraction interface. Board-specific implementations (esp32/, uno_r4/)
// inherit from this. Core logic only ever touches IHal — never board headers.
class IHal {
public:
    virtual void begin()                        = 0;
    virtual void startBLE(const char* name)     = 0;
    virtual bool isClientConnected()            = 0;
    virtual bool receivedData(UsageData& out)   = 0;  // returns true if new data available
    virtual void poll()                         = 0;   // call every loop iteration
    virtual ~IHal() = default;
};
