/**
 * @file TempSensorTSIC.cpp
 *
 * @brief Handler for TSIC 306 temperature sensor
 */

#include "TempSensorTSIC.h"
#include "Logger.h"

#define MAX_CHANGERATE 15

TempSensorTSIC::TempSensorTSIC(int GPIOPin) {
    // Set pin to receive signal from the TSic 306
    tsicSensor_ = new ZACwire(GPIOPin, 306);
    // Start sampling the TSic sensor
    tsicSensor_->begin();
}

float TempSensorTSIC::sample_temperature() const {
    auto temp = tsicSensor_->getTemp(MAX_CHANGERATE);

    if (temp == 222) {
        LOG(WARNING, "Temperature reading failed");
    }
    else if (temp == 221) {
        LOG(WARNING, "Temperature sensor not connected");
    }

    return temp;
}
