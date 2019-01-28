#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
// OLED display TWI address
#define OLED_ADDR   0x3C  
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;

int KAT1=5;
int KAT2=5;



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  
Serial.begin(9600);

pinMode(2,INPUT);

  
}

void loop() {

 //giris
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(25,0);
  display.println("Welcome");
  display.display();
  
 //kat 1
   display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10,25);
  display.println("1st");
  display.display();
  

 //kat 2
   display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(74,25);
  display.println("2nd");
  display.display(); 

     //kat 1
   display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(15,40);
  display.println(KAT1);
  display.display();
     //kat 1
   display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(79,40);
  display.println(KAT2);
  display.display();
  int x= digitalRead(2);
  int y= analogRead(A0);
  Serial.println(y);
  delay(50);
if(x==HIGH && y<700 ){
  display.clearDisplay();
  display.display();
  
  display.setTextSize(2);
  display.setCursor(50,18);
  display.println("Please choose any floor");
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
 
  if(y<700 && y>300){
    KAT1--;
    if(KAT1==-1){
      display.clearDisplay();
      display.display();
      display.setTextSize(3);
      display.setCursor(50,24);
      display.println("FULL");
      display.display();
      delay(2000);
      display.clearDisplay();
      display.display();
      return;
      }
   
   for(int i=0; i<=90; i++){
    motor1.write(i);
    motor2.write(i);
    delay(50);
    }
    delay(1000);
     for(int i=90; i>=0; i--){
    motor1.write(i);
    motor2.write(i);
    delay(50);
    }
    display.clearDisplay();
    display.display();
 
  
  }else{
    if(y<300){
      KAT2--;
         if(KAT2==-1){
          display.clearDisplay();
          display.display();
          display.setTextSize(3);
          display.setCursor(50,24);
          display.println("FULL");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          return;
          }

       for(int i=0; i<=90; i++){
        motor1.write(i);
        motor3.write(i);
         delay(50);
        }
       delay(1000);
           for(int i=90; i>=0; i--){
              motor1.write(i);
              motor3.write(i);
              delay(50);
           }
    display.clearDisplay();
    display.display();
      
    }
  }
 
  


}
}
