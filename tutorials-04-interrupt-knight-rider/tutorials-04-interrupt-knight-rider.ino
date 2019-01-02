const int LEDdizisi[] = {2,3,4,5,6,7,8,9};
int j = 0;

void setup()
{
  Serial.begin(9600);
  
  for(int i=0; i<8 ;i++)    
  { /* For döngüsüyle LEDdizisi elemanlarına ulaşıyoruz */
    pinMode(LEDdizisi[i], OUTPUT); /* LED pinleri çıkış olarak ayarlandı */
  } 
  
  cli();
  /* Ayarlamaların yapılabilmesi için öncelikle kesmeler durduruldu */

  /* Timer1 kesmesi saniyede bir çalışacak şekilde ayarlanacaktır (1 Hz)*/
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 15624;
  /* Bir saniye aralıklar için zaman sayıcısı ayarlandı */
  TCCR1B |= (1 << WGM12);
  /* Adımlar arasında geçen süre kristal hızının 1024'e bölümü olarak ayarlandı */
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  /* Timer1 kesmesi aktif hale getirildi */

  sei();
  /* Timer1 kesmesinin çalışabilmesi için tüm kesmeler aktif hale getirildi */

}

/* Arduino otomatik olarak her saniye aşağıdaki fonksiyonu çalıştıracaktır */
ISR(TIMER1_COMPA_vect){
  for(int i=0; i<8; i++){         
    digitalWrite(LEDdizisi[i],LOW);   
    /* Tüm LED'ler söndürüldü */      
  }
  digitalWrite(LEDdizisi[j],HIGH); 
  /* Sıradaki LED yakıldı */
  j ++;
  if(j > 7)
    j = 0;
}

void loop()
{
 Serial.println("Arduino burada baska islemler yapabilir");
 delay(100);
}
