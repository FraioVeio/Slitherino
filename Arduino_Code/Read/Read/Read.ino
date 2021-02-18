#include <Encoder.h>

#define enc1 2
#define enc2 3

#define pin_pot A0
#define pin_tasto 4

Encoder enc(enc1, enc2);

long pos = 0;
float zoom = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_tasto, INPUT_PULLUP);
}

void loop() {
  bool tasto = 0;

  //encoder
  pos = enc.read()*0.25;

  

  //potenziometro
  zoom = analogRead(pin_pot)/1024;

  //tasto
  tasto = !digitalRead(pin_tasto);
  delay(5);
  
  Serial.print(pos);
  Serial.print(' ');
  Serial.print(zoom);
  Serial.print(' ');
  Serial.print(tasto);
  Serial.print('\n');
}
