
// Sparkle Motion 

/*
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/

// to-do: create header files for other files, reference them

void setup()
{
// Here we'll configure the Arduino pins we're using to
// drive the LED to be outputs:
lcd.begin(16, 2);
lcd.clear();
pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
pinMode(PIR_IN, INPUT);

void loop()
{
  pir_state_a = analogRead(PIR_IN);
  pir_state_d = digitalRead(PIR_IN);
  showRGB(pir_state_a * 3);
  lcd.print(pir_state_d);
  
if (pir_state_d == HIGH){
  redLight();
} else {
  greenLight();
}






