#define LED_1   3           //Plug the LED 1 in the PIN 3
#define INCREASE_TIME 200   // 0.2 sec


void setup() {
  pinMode(LED_1, OUTPUT); // Initialize the PWN pin as output
}

void loop() {
  // Increase the light of the LED
  for(int i=0; i<=255; i=i+10){
    analogWrite(LED_1,i);
    delay(INCREASE_TIME);
  }
  // Decrease the light of the LED
  for(int i=255; i>=0; i=i-10){
    analogWrite(LED_1,i);
    delay(INCREASE_TIME);
  }
}
