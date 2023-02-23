#include "Pushbutton.hpp"

#define     BUTTON_PIN                              GPIO_PIN_13
#define     BUTTON_PORT                             GPIOC
#define     BUTTON_GPIO_CLK_ENABLE()                __HAL_RCC_GPIOC_CLK_ENABLE()

void PUSHBUTTON::PUSHBUTTON_Setup() {

    BUTTON_GPIO_CLK_ENABLE();
    GPIO_BUTTON.Pin = BUTTON_PIN;
    GPIO_BUTTON.Mode = GPIO_MODE_INPUT;
    GPIO_BUTTON.Pull = GPIO_PULLUP;
    GPIO_BUTTON.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_BUTTON);
}

void PUSHBUTTON::PUSHBUTTON_Update() {
    buttonState = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN);
}

int PUSHBUTTON::GetButtonState(){
    PUSHBUTTON_Update();
	return buttonState;
}

int PUSHBUTTON::GetLastButtonState(){
	return lastButtonState;
}


// /*
//   Debounce
//
//   Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
//   press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
//   minimum delay between toggles to debounce the circuit (i.e. to ignore noise).
//
// */
//
// #include "Pushbutton.hpp"
//
//
// // debouncing vars moved to .hpp
//
// void PUSHBUTTON::PUSHBUTTON_Setup() {
//   pinMode(buttonPin, INPUT);
// }
//
// void PUSHBUTTON::PUSHBUTTON_Update() {
//   // read the state of the switch into a local variable:
//   int reading = digitalRead(buttonPin);
//
//   // check to see if you just pressed the button
//   // (i.e. the input went from LOW to HIGH), and you've waited long enough
//   // since the last press to ignore any noise:
//
//   // If the switch changed, due to noise or pressing:
//   /*if (reading != lastButtonState) {
//     // reset the debouncing timer
//     lastDebounceTime = millis();
//   }*/
//
//   //if ((millis() - lastDebounceTime) > debounceDelay) {
//     // whatever the reading is at, it's been there for longer than the debounce
//     // delay, so take it as the actual current state:
//
//     // if the button state has changed:
//     if (reading != buttonState) {
//       buttonState = reading;
//     }
//   //}
//
//   // save the reading. Next time through the loop, it'll be the lastButtonState:
//   lastButtonState = reading;
//
//   /* // code from ex
//   newbuttonState = digitalRead(buttonPin);
//   if (newbuttonState == HIGH)
//   {
//     digitalWrite(LED, HIGH);
//   }
//   else{
//     digitalWrite(LED, LOW);
//   } */
//
// }
//
// int PUSHBUTTON::GetbuttonState(){
// 	return buttonState;
// }
//
// int PUSHBUTTON::GetlastButtonState(){
// 	return lastButtonState;
// }
//
//
// float PUSHBUTTON::GetVoltage(){
// 	return voltage;
// }
