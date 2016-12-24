
//Including temp sensor library
#include <dht.h>

#define dht_dpin A0 //no ; here. Set equal to channel sensor is on

dht DHT;    // dht - define 

//Including lcd library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
 /*CONNECTION FOR LCD
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
 * 
  */

int input='0'; //input to be used
String input2; //variable for string input


void setup() {
 
  lcd.begin(16,2);     // 16 colums 2 rows
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);    //baud rate for all serial communications
 
 }

void loop() {
  char strng; //textbox content
  lcd.clear();
  
     if(Serial.available()>0){
        input = Serial.read();
     }
 
// forward
     if(input == '1'){
       digitalWrite(13,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(10,HIGH);
     }

 //back  
      else if(input == '2'){
        digitalWrite(13,LOW);
        digitalWrite(9,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(10,LOW);
     }

//right
     else if(input == '3'){
        digitalWrite(13,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(8,HIGH);
        digitalWrite(10,LOW);
     }

  //left 
     else if(input == '4'){
       digitalWrite(13,LOW);
       digitalWrite(9,HIGH);
       digitalWrite(8,LOW);
       digitalWrite(10,HIGH);
     }

   //default state
    else if(input == '0'){
        digitalWrite(13,LOW);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(10,LOW);
        lcd.clear();
    }

//string to be displayed on lcd
      else if(input == '5'){
       
          Serial.flush();
          while(!Serial.available()) ; 
          input2 = Serial.readString();
          strng = input2.length();
          lcd.clear();
          delay(10); // delay of 10 ms
          lcd.setCursor(0, 0); // row 0 col 0
          lcd.print(input2.c_str()); // character values are fetched by c_str() and converts string 
          delay(1000);
          lcd.clear();
          input = '0';
      }


 //scrolling of text on lcd
 else if(input == '6'){ 
  
      lcd.clear();
      delay(10);
      lcd.setCursor(16, 0); // col 16
      lcd.print(input2.c_str());
      for (int i = 0;i<16+strng;i++) {
      lcd.scrollDisplayLeft(); 
      delay(200);
    }
    
    lcd.clear();
    input = '0';
  }

    //temp sensor
  else if(input = '7'){
    DHT.read11(dht_dpin);

    Serial.print("Hum= ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temp= ");
    Serial.print(DHT.temperature); 
    Serial.println(" deg C  ");
    delay(800);
  }
}
