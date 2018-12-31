int ledPin = 13;
boolean led_durumu = LOW;

void setup(){
  pinMode(ledPin,OUTPUT);
  
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
 led_durumu = !led_durumu;
  digitalWrite(ledPin, led_durumu);
}

void loop(){
delay(10000);
}
