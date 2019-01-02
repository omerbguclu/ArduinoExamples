/*
Arduino Tutorials
Episode 2
Switch3 Program (debounced)
Written by: Jeremy Blum
*/

int ledPin = 7;
int switchPin = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;
/* LED'in bağlı olduğu pin 5 olarak belirlendi */

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last != current)
  {
    delay(100);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  
  digitalWrite(ledPin, ledOn);

}
