#define BUZZER_PIN 3
#define BUTTON1_PIN 4 
#define BUTTON2_PIN 5
#define BUTTON3_PIN 6
#define BUTTON4_PIN 7 
#define JOY_Y A2
#define JOY_X A3

int octaveShift = 0;  
unsigned long lastMoveTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
}

void readJoystick() {
  int y = analogRead(JOY_Y);
  int x = analogRead(JOY_X);
  Serial.println(x);
  unsigned long now = millis();

  // Only allow change every 500ms to avoid rapid toggling
  if (now - lastMoveTime > 1000) {
      if (y < 300 && octaveShift <1) {
      octaveShift++;
      Serial.print("Octave up: "); Serial.println(octaveShift);
      lastMoveTime = now;
    } else if (y > 700 && octaveShift > -1) {
      octaveShift--;
      Serial.print("Octave down: "); Serial.println(octaveShift);
      lastMoveTime = now;
     
    }
  }
  Serial.print("Octave: ");
  Serial.println(octaveShift);
  
}

void loop() {
  readJoystick();
  int baseNotes[] = {261, 293, 329, 392};
  float multiplier = pow(2, octaveShift);

   if (digitalRead(BUTTON1_PIN) == LOW) {
    Serial.println("DO");
    buzz(baseNotes[0] * multiplier);
    
  }

  if (digitalRead(BUTTON2_PIN) == LOW) {
    Serial.println("RE");
    buzz(baseNotes[1] * multiplier);
    
  }

  if (digitalRead(BUTTON3_PIN) == LOW) { 
    Serial.println("MI");
    buzz(baseNotes[2] * multiplier); 
  
  }

  if (digitalRead(BUTTON4_PIN) == LOW) {
    Serial.println("FA");
    buzz(baseNotes[3] * multiplier);
    
  }

}



void buzz(int frequency) {
  int duration = 1000000 / frequency;  
  for (int i = 0; i < 35; i++) {  
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(duration); 
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(duration);
  }
}
