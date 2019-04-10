/************************************************************************************
 * PROJETO CAPIBARIBE 
 * DASHBOARD .................................. Versão 1.0
 * 
 * RESUMO:
 *  Mostrar dados como Velocidade, RPM e Temperatura do motor na tela LCD
 *  Mostrar dados como Pressão dos pneus, Nivel de bateria, Temperatura do motor, 
 *  da bateria e do controlador em LEDs
 *  
 *************************************************************************************/

#include <LiquidCrystal.h>  
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
 
// DEFINIÇAO DE DESENHOS PARA O LCD
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

//DEFININDO OS PINOS DE CADA LED
 #define LED_Temp_Motor                30
 #define LED_Pneu_Vermelho             25
 #define LED_Pneu_Amarelo              26
 #define LED_Pneu_Verde                27
 #define LED_Nivel_Bateria_Vermelho    22
 #define LED_Nivel_Bateria_Amarelo     23
 #define LED_Nivel_Bateria_Verde       24
 #define LED_Temp_Bateria_Vermelho     40
 #define LED_Temp_Bateria_Amarelo      41
 #define LED_Temp_Bateria_Verde        42
 #define LED_Temp_Controlador_Vermelho 44
 #define LED_Temp_Controlador_Amarelo  45
 #define LED_Temp_Controlador_Verde    43
 
 int Temperatura_Motor = 90;
 int Pressao_Pneus = 0;
 int Nivel_Bateria = 100;
 int Temperatura_Bateria = 30;
 int Temperatura_Controlador = 28;
 int Velocidade = 100;
 int RPM = 2000;
 int QntBlocos = 0;
  
void setup()   
{  

//INICIALIZANDO A TELA LCD E CRIANDO OS CARACTERES NOVOS
     lcd.begin(16, 2);  
     lcd.setCursor(0,1);  
     lcd.createChar(1,TijoloVelocidade);  
     lcd.createChar(2,Barra);  
     lcd.createChar(3,Grau); 
     lcd.createChar(4,TijoloRPM);   


//SUBDIVIDINDO O LCD E ESCREVENDO A TEMPERATURA ATUA DO MOTOR
     lcd.setCursor(9,1); 
     lcd.print(Temperatura_Motor);
     lcd.setCursor(12,1);
     lcd.write(3);
     lcd.print('C');

//LEDs
     pinMode(LED_Temp_Motor,OUTPUT);
     digitalWrite(LED_Temp_Motor, LOW);

     pinMode(LED_Pneu_Vermelho,OUTPUT);
     digitalWrite(LED_Pneu_Vermelho, LOW);
     pinMode(LED_Pneu_Amarelo,OUTPUT);
     digitalWrite(LED_Pneu_Amarelo, LOW);
     pinMode(LED_Pneu_Verde,OUTPUT);
     digitalWrite(LED_Pneu_Verde, LOW);
     
     pinMode(LED_Nivel_Bateria_Vermelho,OUTPUT);
     digitalWrite(LED_Nivel_Bateria_Vermelho, LOW);
     pinMode(LED_Nivel_Bateria_Amarelo,OUTPUT);
     digitalWrite(LED_Nivel_Bateria_Amarelo, LOW);
     pinMode(LED_Nivel_Bateria_Verde,OUTPUT);
     digitalWrite(LED_Nivel_Bateria_Verde, LOW);
     
     pinMode(LED_Temp_Bateria_Vermelho,OUTPUT);
     digitalWrite(LED_Temp_Bateria_Vermelho, LOW);
     pinMode(LED_Temp_Bateria_Amarelo,OUTPUT);
     digitalWrite(LED_Temp_Bateria_Amarelo, LOW);
     pinMode(LED_Temp_Bateria_Verde,OUTPUT);
     digitalWrite(LED_Temp_Bateria_Verde, LOW);
     
     pinMode(LED_Temp_Controlador_Vermelho,OUTPUT);
     digitalWrite(LED_Temp_Controlador_Vermelho, LOW);
     pinMode(LED_Temp_Controlador_Amarelo,OUTPUT);
     digitalWrite(LED_Temp_Controlador_Amarelo, LOW);
     pinMode(LED_Temp_Controlador_Verde,OUTPUT);
     digitalWrite(LED_Temp_Controlador_Verde, LOW);


  //SERIAL
    Serial.begin(9600);
}  
  
void loop()  
{  
   lcd.setCursor(8,1);  
   lcd.write(2);
   lcd.display();
   F_Velocidade();
   F_RPM();
   
/********************************TEMPERATURA DO MOTOR*************************************/   
    Serial.print("Temperatura_Motor: ");
    while(Serial.read()<0) Temperatura_Motor = Serial.parseInt();
    Serial.println(Temperatura_Motor);
    
    if(Temperatura_Motor > 98){
        digitalWrite(LED_Temp_Motor, HIGH);
     }
    else{
      digitalWrite(LED_Temp_Motor, LOW);
    }
     
    //Espaço da Temperatura
     lcd.setCursor(9,1); 
     lcd.print(Temperatura_Motor);
     lcd.setCursor(12,1);
     lcd.write(3);
     lcd.print('C');

/********************************PRESSAO DOS PNEUS*************************************/   
    Serial.print("Pressao_Pneus: ");
    while(Serial.read()<0) Pressao_Pneus = Serial.parseInt();
    Serial.println(Pressao_Pneus);
    if(Pressao_Pneus > 98){
        digitalWrite(LED_Pneu_Amarelo, HIGH);
        digitalWrite(LED_Pneu_Vermelho, LOW);
        digitalWrite(LED_Pneu_Verde, LOW);
     }
    else{
      digitalWrite(LED_Pneu_Verde, HIGH);
      digitalWrite(LED_Pneu_Amarelo, LOW);
      digitalWrite(LED_Pneu_Vermelho, LOW);
      
    }

/********************************NIVEL DE BATERIA*************************************/  
    Serial.print("Nivel_Bateria: ");
    while(Serial.read()<0) Nivel_Bateria = Serial.parseInt();
    Serial.println(Nivel_Bateria);
    if(Nivel_Bateria > 70){
        digitalWrite(LED_Nivel_Bateria_Amarelo, LOW);
        digitalWrite(LED_Nivel_Bateria_Vermelho, LOW);
        digitalWrite(LED_Nivel_Bateria_Verde, HIGH);
     }
    else{
      digitalWrite(LED_Nivel_Bateria_Verde, HIGH);
      digitalWrite(LED_Nivel_Bateria_Amarelo, LOW);
      digitalWrite(LED_Nivel_Bateria_Vermelho, LOW);
      
    } 
/********************************TEMPERATURA DA BATERIA*************************************/ 
    Serial.print("Temperatura_Bateria: ");
    while(Serial.read()<0) Temperatura_Bateria = Serial.parseInt();
    Serial.println(Temperatura_Bateria);
    if(Temperatura_Bateria > 98){
        digitalWrite(LED_Temp_Bateria_Amarelo, HIGH);
        digitalWrite(LED_Temp_Bateria_Vermelho, LOW);
        digitalWrite(LED_Temp_Bateria_Verde, LOW);
     }
    else{
      digitalWrite(LED_Temp_Bateria_Verde, HIGH);
      digitalWrite(LED_Temp_Bateria_Amarelo, LOW);
      digitalWrite(LED_Temp_Bateria_Vermelho, LOW);
      
    }
/********************************TEMPERATURA DO CONTROLADOR*************************************/  
    Serial.print("Temperatura_Controlador: ");
    while(Serial.read()<0) Temperatura_Controlador = Serial.parseInt();
    Serial.println(Temperatura_Controlador);
    if(Temperatura_Controlador > 98){
        digitalWrite(LED_Temp_Controlador_Amarelo, HIGH);
        digitalWrite(LED_Temp_Controlador_Vermelho, LOW);
        digitalWrite(LED_Temp_Controlador_Verde, LOW);
     }
    else{
      digitalWrite(LED_Temp_Controlador_Verde, HIGH);
      digitalWrite(LED_Temp_Controlador_Amarelo, LOW);
      digitalWrite(LED_Temp_Controlador_Vermelho, LOW);
      
    }   
/***********************************************************************************************/

   Serial.println();
}
