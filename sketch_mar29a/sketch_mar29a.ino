/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-water-sensor
 */
#define LED_PIN   13
#define POWER_PIN   2
#define SIGNAL_PIN  A7
#define THRESHOLD   300
#define BUZZER  3

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);   // configure D2 pin as an OUTPUT
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(LED_PIN,   LOW); // turn LED OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  if (value > THRESHOLD) {
    Serial.print("The water is detected");
    digitalWrite(LED_PIN, HIGH);  // turn LED ON
    tone(BUZZER, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(BUZZER);
  } else {
    digitalWrite(LED_PIN, LOW);   // turn LED OFF
  }
}
