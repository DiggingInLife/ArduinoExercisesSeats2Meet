#define LED_1       2             // Plug the LED 1 in the PIN 2
#define LED_2       3             // Plug the LED 2 in the PIN 3
#define DELAY_TIME_LED_1  1000    // 1 sec
#define DELAY_TIME_LED_2  300     // 0,6 sec

byte led_1_state = LOW;           // Create variables to save the state of the LED
byte led_2_state = LOW;

/* Blink with 2 leds with different periods  it isn't as simple as before,
 * we need to know when we have to blink and for that we need to save the
 * time. To do that we need 'unsigned long' variables because it's
 * the return type of 'millis()' that give us the current time in miliseconds.
 */
unsigned long led_1_next_blink, led_2_next_blink;

void setup() {
  pinMode(LED_1, OUTPUT); // Initialize the digital pin as output
  pinMode(LED_2, OUTPUT);

  led_1_next_blink = led_2_next_blink = millis(); // This is our start point
}

// We need to create a function to wait
unsigned long wait_timing(unsigned long next_time_ms){
  // Save the current time in the variable t
  unsigned long t = millis();
  /* We check if we already pass the dead line time.
   * If not we wait the restant time left.
   * Else we don't need to wait.
   */
  if(t < next_time_ms){
    delay(next_time_ms - t);
    // We save again the current time after wait
    t = millis();
  }
  // This return is the current time
  return t;
}

void loop() {
  
  /*  This is a loop so the first iteration led_1_next_blink will be the same than led_2_next_blink
   *  because we initalize with the same value at the setup() but the rest of iteratinos 
   *  (may) will be different. So we ask with min(value1,value2) who its the next and call our
   *  funtion wait_timing(value)
   */
  unsigned long current_ms =  wait_timing(min(led_1_next_blink,led_2_next_blink));

  // We ask if we was waiting for the LED_1
  if(current_ms >= led_1_next_blink){
    // We need to add the delay time of the LED_1 for the next blink
    led_1_next_blink = current_ms + DELAY_TIME_LED_1;
    // If the current state is LOW change it to HIGH in another case change it to LOW
    led_1_state = (led_1_state == LOW ? HIGH : LOW);
    // Change the output of the LED_1
    digitalWrite(LED_1,led_1_state);
  }
  // We ask if we was waiting for the LED_2
  if(current_ms >= led_2_next_blink){
    // We need to add the delay time of the LED_2 for the next blink
    led_2_next_blink = current_ms + DELAY_TIME_LED_2;
    // If the current state is LOW change it to HIGH in another case change it to LOW
    led_2_state = (led_2_state == LOW ? HIGH : LOW);
    // Change the output of the LED_2
    digitalWrite(LED_2,led_2_state);
  }
}
