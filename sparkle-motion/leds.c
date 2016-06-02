// led stuff

#include <LiquidCrystal.h>
#include <setup.h>


LiquidCrystal lcd(12,6,5,4,3,7);

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int PIR_IN = 2;

// This variable controls how fast we loop through the colors.
// (Try changing this to make the fading faster or slower.)

int DISPLAY_TIME = 10;  // In milliseconds
int pir_state_a = 0;
int pir_state_d = 0;




// Light colours


// Red (turn just the red LED on);

void redLight() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  
//  delay(1000);
}

// Green (turn just the green LED on):


void greenLight() {
  
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  
//  delay(1000);
}

// Yellow (turn just the yellow LED on):


void yellowLight() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

// delay(1000);
}

// Blue (turn just the blue LED on):

void blueLight() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

// delay(1000);
}