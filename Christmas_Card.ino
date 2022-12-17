/*
  Christmas Card

 */

// These constants won't change:
//christmas lights
const int LED_GREEN = 2;
const int LED_ORANGE = 7;
const int LED_RED = 10;
const int BUTTON = 5;
const int BUZZER = 9;

int buttonState = 0;

int tempo = 200;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

void playTheTone(char note, int duration) {
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };

  for (int i = 0; i <= sizeof(tones); i++) {
    if (note == notesName[i]) {
      tone(BUZZER, tones[i], duration);
    }
  }
}

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH){

    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_ORANGE, HIGH);
    digitalWrite(LED_RED, HIGH);

    for (int i = 0; i <= sizeof(notes)-1; i++) {
    if (notes[i] == ' ') {
      delay(duration[i] * tempo);

      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_RED, HIGH);


    } else {
      playTheTone(notes[i], duration[i] * tempo);

      digitalWrite(LED_ORANGE, HIGH);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, HIGH);
      
      delay(100);

      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
  
    }
    delay((tempo*2)*duration[i]);

    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_ORANGE, LOW);
    digitalWrite(LED_RED, HIGH);

  }
  } 
}
