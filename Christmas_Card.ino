/*
  Christmas Card

 */

// These constants won't change:
const int buttonPin = 2;    // pin that the sensor is attached to
const int buzzerPin = 8;
const int redLedPin = 9;
const int greenLedPin = 10;

// variables:
int buttonState = 1;
int tempo = 200;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

void playTheTone(char note, int duration) {
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };

  for (int i = 0; i <= sizeof(tones); i++) {
    if (note == notesName[i]) {
      tone(buzzerPin, tones[i], duration);
    }
  }
}

//the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(buttonPin, INPUT); //initialize "button" as an input
  pinMode(redLedPin, OUTPUT); //initialize "led" as an output
  pinMode(greenLedPin, OUTPUT); //initialize "led" as an output
  pinMode(buzzerPin, OUTPUT); //initialize "buzzer" as an output
}

//the loop function runs over and over again forever
void loop()
{
  buttonState = digitalRead(buttonPin); //read if button is pressed

  //if button is pressed
  if(buttonState == LOW)
  {
    // Jingle Bells
    for (int i = 0; i <= sizeof(notes)-1; i++){
    if (notes[i] == ' ') {
      delay(duration[i] * tempo);
      
      digitalWrite(redLedPin, HIGH); //light the led
      digitalWrite(greenLedPin, LOW); //light the led
      delay(100);
      digitalWrite(redLedPin, LOW); //turn off the led
      digitalWrite(greenLedPin, HIGH); //light the led
      delay(100);
    } else {
      playTheTone(notes[i], duration[i] * tempo);
      
      digitalWrite(redLedPin, HIGH); //light the led
      digitalWrite(greenLedPin, LOW); //light the led
      delay(100);
      digitalWrite(redLedPin, LOW); //turn off the led
      digitalWrite(greenLedPin, HIGH); //light the led
      delay(100);
    }
    delay((tempo*2)*duration[i]);
  	}


    int buttonState = 1; //assigned the value 1 to the "buttonState" variable, as the button is pressed again
  }
}
