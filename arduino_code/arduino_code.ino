void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int led_specifier = Serial.parseInt();
  if(led_specifier == 1){
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)

  }
  else if(led_specifier == 0){
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  }
}
