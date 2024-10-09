#include <Arduino.h>

// Going to test out the builtin j-tag interface
void setup() {
    Serial.begin(115200);
    Serial.println("Starting...");
    pinMode(LED_BUILTIN, OUTPUT);
    delay(1000);
}

void loop() {
    Serial.println("LED HIGH");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED LOW");
    delay(1000);
}
