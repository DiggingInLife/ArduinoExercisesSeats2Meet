#define PIN_2       2       
#define DELAY_TIME  1000   // 1 sec

void setup() {
  pinMode(PIN_2, OUTPUT); // Initialize the digital pin as output
  digitalWrite(PIN_2, HIGH); // Turn the LED on (HIGH is the voltaje level)

}

void loop() {
  digitalWrite(PIN_2, HIGH); // Turn the LED on (HIGH is the voltaje level)
  delay(DELAY_TIME);          // Wait for a second
  digitalWrite(PIN_2, LOW);  // Turn of the LED
  delay(DELAY_TIME);          // Wait for a second
}
