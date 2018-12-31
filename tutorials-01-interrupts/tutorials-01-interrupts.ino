int ledPin =         13;
boolean led_state = LOW;
int i =               0;

void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  
  cli();

  // Timer1 kesmesi ayarlanıyor
  TCNT1  = 0;
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 15624;  // 1 saniye çalışması için gerekli zaman kesmesi frekansı
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}


ISR(TIMER1_COMPA_vect){     //Her kesmeye girildiğinde otomatik çalıştırılacak fonksiyon.
  led_state = !led_state;
  digitalWrite(ledPin, led_state);
}

void loop(){
  Serial.print("loop ");
  Serial.println(i++);
  delay(5000);
}
