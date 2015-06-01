#define STATUS_LED (13)
#define BLINK_ON_DELAY_MS (900)
#define BLINK_OFF_DELAY_MS (100)

void setup() {
  // put your setup code here, to run once:
  
  pinMode(STATUS_LED, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(STATUS_LED, HIGH);
  delay(BLINK_ON_DELAY_MS);
  digitalWrite(STATUS_LED, LOW);
  delay(BLINK_OFF_DELAY_MS);
}
