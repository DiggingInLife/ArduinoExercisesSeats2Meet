#define BUTTON      2             // Plug the wire of button in the PIN 2
#define LED_1       3             // Plug the LED 1 in the PIN 3



void setup() {
  pinMode(BUTTON, INPUT); // Initialize the digital pin as input
  pinMode(LED_1, OUTPUT); // Initialize the digital pin as output
}

void loop() {
  // Save the state in the variable button_state
  int button_state = digitalRead(BUTTON);
  // If the button is press then light the LED
  digitalWrite(LED_1,button_state);
}
