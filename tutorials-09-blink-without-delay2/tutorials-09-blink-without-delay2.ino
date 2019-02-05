boolean LEDstate1, LEDstate2 = LOW;
int nextTime1 = 1000;  // Do this every second or 1000 milliseconds
int nextTime2 = 600;  // Do this every 600 milliseconds
long int goTime1, goTime2;
#define ledpin 13
#define ledpin2 7

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(7, OUTPUT);
  goTime1 = millis();
  goTime2 = millis();
}

void loop() {
  if (millis() >= goTime1) functionGo1();
  if (millis() >= goTime2) functionGo2();
}

void functionGo1() {
  if (LEDstate1 == HIGH) {
    digitalWrite(ledpin, LOW);
    LEDstate1 = LOW;
  }
  else {
    digitalWrite(ledpin, HIGH);
    LEDstate1 = HIGH;
  }
  goTime1 = millis() + nextTime1;
}

void functionGo2() {
  if (LEDstate2 == HIGH) {
    digitalWrite(ledpin2, LOW);
    LEDstate2 = LOW;
  }
  else {
    digitalWrite(ledpin2, HIGH);
    LEDstate2 = HIGH;
  }
  goTime2 = millis() + nextTime2;
}
