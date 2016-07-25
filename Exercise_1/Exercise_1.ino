#define PIN_13 13         // Pin 13 has an LED connected on most Arduino
#define DELAY_TIME 1000   // 1 sec

void setup() {
  pinMode(PIN_13, OUTPUT); // Initialize the digital pin as output
}

void loop() {
  digitalWrite(PIN_13, HIGH); // Turn the LED on (HIGH is the voltaje level)
  delay(DELAY_TIME);          // Wait for a second
  digitalWrite(PIN_13, LOW);  // Turn of the LED
  delay(DELAY_TIME);          // Wait for a second
}
