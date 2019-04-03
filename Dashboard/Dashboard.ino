#include <LiquidCrystal.h>  
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

byte TijoloRPM[8] = 
{
  B00000,  
  B11111,  
  B11111,  
  B11011,  
  B11011,  
  B11011,  
  B11111,  
  B11111};

byte TijoloVelocidade[8] = 
{
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B11111,  
  B00000};
byte Barra[8] = 
{
  B00100,  
  B00100,  
  B00100,  
  B00100,  
  B00100,  
  B00100,  
  B00100,  
  B00100};

byte Grau[8] = 
{
  B01110,  
  B01010,  
  B01110,  
  B00000,  
  B00000,  
  B00000,  
  B00000,  
  B00000};

 #define LED 22
 int Temperatura = 90;
 int Velocidade = 100;
 int RPM = 2000;
 int QntBlocos = 0;
  
void setup()   
{  
 lcd.begin(16, 2);  
 lcd.setCursor(0,1);  
 lcd.createChar(1,TijoloVelocidade);  
 lcd.createChar(2,Barra);  
 lcd.createChar(3,Grau); 
 lcd.createChar(4,TijoloRPM);   
 Serial.begin(9600);

//Espaço da Temperatura
     lcd.setCursor(9,1); 
     lcd.print(Temperatura);
     lcd.setCursor(12,1);
     lcd.write(3);
     lcd.print('C');

//LEDs
     pinMode(LED,OUTPUT);
     digitalWrite(LED, LOW);

}  
  
void loop()  
{  
   lcd.setCursor(8,1);  
   lcd.write(2);
   digitalWrite(LED, HIGH);
   F_Velocidade();
   F_RPM();
    
}
