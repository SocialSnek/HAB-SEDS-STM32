#include "AnalogPin.hpp"

// ***********************************

void ANALOGPIN::ANALOGPIN_Setup() {
    // HAL_ADC_Init()
}

void ANALOGPIN::ANALOGPIN_Update() {

}

int ANALOGPIN::getAnalogValue() {
    return 0;
}

// #include "AnalogPin.hpp"
//
//
// void ANALOGPIN::ANALOGPIN_Setup() {
// 	pinMode( analogPin, INPUT );
// }
//
// void ANALOGPIN::ANALOGPIN_Update() {
// 	// read the value from the sensor:
// 	analogValue = analogRead( analogPin );
// }
//
//
// int ANALOGPIN::getAnalogValue() {
// 	return analogValue;
// }
