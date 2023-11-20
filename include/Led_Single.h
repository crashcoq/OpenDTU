// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "PinMapping.h"
#include <TaskSchedulerDeclarations.h>
#include <TimeoutHelper.h>

#define LEDSINGLE_UPDATE_INTERVAL 2000

class LedSingleClass {
public:
    LedSingleClass();
    void init(Scheduler* scheduler);

    void turnAllOff();
    void turnAllOn();

private:
    void loop();

    Task _loopTask;

    enum class LedState_t {
        On,
        Off,
        Blink,
    };

    LedState_t _ledState[PINMAPPING_LED_COUNT];
    LedState_t _allState;
    TimeoutHelper _updateTimeout;
    TimeoutHelper _blinkTimeout;
    uint8_t _ledActive = 0;
};

extern LedSingleClass LedSingle;