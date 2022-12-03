//Christmas lights
const int LED_GREEN = 2;
const int LED_ORANGE = 7;
const int LED_RED = 10;
  
void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop()
{
 
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_ORANGE, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(500); 
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_ORANGE, LOW);
  delay(500); 
  digitalWrite(LED_ORANGE, HIGH);
  digitalWrite(LED_RED, LOW);
  delay(500);
}
