int ledPin =         13;
int potpin =          0;
boolean led_state = LOW;
int i =               0;
int val;

void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  
  cli();

  // Timer1 kesmesi ayarlanıyor
  TCNT1  = 0;
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 15624/5;  // 1/5 saniye çalışması için gerekli zaman kesmesi frekansı
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}


ISR(TIMER1_COMPA_vect){     //Her kesmeye girildiğinde otomatik çalıştırılacak fonksiyon.
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("Servo Position: ");
  Serial.println(val);
}

void loop(){
  Serial.print("Loop count: ");
  Serial.print(i++);
  Serial.print(" Led state change to -> ");
  led_state = !led_state;
  digitalWrite(ledPin, led_state);
  Serial.println(led_state);
  delay(5000);
}
