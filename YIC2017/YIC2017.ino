#include <dht.h>
#include <LiquidCrystal.h>

int humid;
int temp;

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

dht DHT;

#define DHT11_PIN 7

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);

  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);

  humid = DHT.humidity;
  temp = DHT.temperature;

  if (temp > 25) {
    digitalWrite (4, HIGH);
  } else {
    digitalWrite (4, LOW);
  }
  
}
