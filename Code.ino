const int ledPins[] = {9,10,11};
const int button = 2;
const int buzzer = 8;

unsigned long startTime;
unsigned long reactionTime;
unsigned long bestTime = 14000;

void setup() {
  DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3); // set ledPins as output
  
  pinMode(button, INPUT);  // set button as input
  pinMode(buzzer, OUTPUT);  // set buzzer as output

  Serial.begin(9600);

  randomSeed(analogRead(A0));
}

void loop() {
  Serial.println("Get Ready...");

  randomLedPattern();

  turnLedsOn();
  startTime = millis();

  while(digitalRead(button) == LOW){
    // wait for button
  }

  reactionTime = millis() - startTime;

  turnLedsOff();

  tone(buzzer, 1000); // button press signals buzzer
  delay(1000);
  noTone(buzzer);

  Serial.print("Your Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  if(reactionTime < bestTime){
    bestTime = reactionTime;
  }

  Serial.print("Current Best Time: ");
  Serial.print(bestTime);
  Serial.println(" ms");

  delay(2000);
  }   

// make musical chairs
void randomLedPattern() {
  int patternLength = random(10, 25);

  for (int i = 0; i < patternLength; i++) {
    int randomLed = random(0, 3);            
      analogWrite(ledPins[randomLed], 128);
      delay(200);
      analogWrite(ledPins[randomLed], 0);
      delay(100);
  }
}

// turn Leds off
void turnLedsOff() {
  PORTB &= ~((1 << PB1) | (1 << PB2) | (1 << PB3));
}

// turn Leds on
void turnLedsOn() {
  PORTB |= (1 << PB1) | (1 << PB2) | (1 << PB3); 
}
