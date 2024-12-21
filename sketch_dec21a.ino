/*
 * Kết nối:
 *          VCC  ---- 5V (Arduino)
 *          GND  ---- GND (Arduino)
 *          DATA ----  2 (Arduino)
 */
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7 

#include <LiquidCrystal.h>

#define DIEUKHIEN 13 //dieu khien C1815

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

//Khởi tạo với các chân
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(void) 
{ 
 Serial.begin(9600); 
 // Start up the library 
 sensors.begin(); 

   //Thông báo đây là LCD 1602
  lcd.begin(16, 2);
  //In ra màn hình lcd dòng chữ Toi yeu Arduino
  lcd.print("Nhiet do hien tai");

  //cau hinh chan dieu khien
  pinMode(DIEUKHIEN, OUTPUT);
  digitalWrite(DIEUKHIEN, LOW);
} 
void loop(void) 
{ 
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures();
 Serial.println("DONE"); 
 Serial.print("Temperature is: "); 
 float nhietdo =sensors.getTempCByIndex(0);
 Serial.print(nhietdo);
 delay(1000); 

   // đặt con trỏ vào cột 0, dòng 1
  // Lưu ý: dòng 1 là dòng thứ 2, dòng 0 là dòng thứ 1. Nôm na, nó đếm từ 0 từ không phải từ 1
  lcd.clear();
  lcd.print("Nh.do hien tai:");
  lcd.setCursor(3, 1);
  // In ra dong chu
  lcd.print(nhietdo);
  lcd.setCursor(9, 1);
  lcd.print("do C");

  //Kiem tra nhiet do de bat tat den suoi 
  if(nhietdo<24.50) {
    digitalWrite(DIEUKHIEN, HIGH);
  }

  if(nhietdo>28.50) {
    digitalWrite(DIEUKHIEN, LOW);
  }
}
