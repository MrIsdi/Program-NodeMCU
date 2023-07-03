#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int LED = 13;
int Buzzer = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float suhu = dht.readTemperature();
  float lembab = dht.readHumidity();
  Serial.println("Suhu = "+String(suhu)+" Lembab = "+String(lembab));

  if(suhu > 30){
    digitalWrite(LED, 1);
    digitalWrite(Buzzer, 1);
  }else{
    digitalWrite(LED, 0);
    digitalWrite(Buzzer, 0);
  }
  delay(1000);
}
