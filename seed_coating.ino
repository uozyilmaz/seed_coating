

//-----------------------------
//uozyilmaz 2020
//Rotary seed coating device
//-----------------------------

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define dirPin 3
#define stepPin 2
int uu = 15000; // for soft start
float za = 0;
int t=0;
int yon=0;
int uusinir= 6000; // for waiting
//3000  > 210 rpm 
//5000  > 122
//7000  > 90
//8000  > 78 
//10000 > 62.5
//12000 > 52 
unsigned long eskizaman=0;
unsigned long eskiz=0;
unsigned long yenizaman;

void setup() 
{
pinMode(stepPin, OUTPUT);
pinMode(dirPin, OUTPUT);

Serial.begin(9600);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
{
  Serial.println(F("Allocation failed"));
  for(;;);
}
// display works with informative values, not live 
display.clearDisplay();
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,0);
display.setTextSize(2);
display.print(F("100"));
display.setTextSize(1);
display.print(F(" rpm"));
display.setTextSize(2);
display.print(F("  C"));
display.setTextSize(1);
display.println(F("wise"));
display.println();
t=(int)za; 
display.setTextSize(2);
display.print(t);
display.setTextSize(1);
display.print(F(" s"));
display.setTextSize(2);
display.print(F(" 600"));
display.setTextSize(1);
display.println(F(" s"));
display.display();
digitalWrite(dirPin, 0);
}

void loop() 
{
yenizaman=millis();
if(yenizaman-eskizaman>500)
{
  uu=uu-500;
  za=za+0.5;
  if (uu<uusinir){uu=uusinir;}
  eskizaman=yenizaman;
}
if (yenizaman-eskiz>20000)
{    
  eskiz=yenizaman;
}
digitalWrite(stepPin, HIGH);
delayMicroseconds(uu);
digitalWrite(stepPin, LOW);
delayMicroseconds(uu);
}
