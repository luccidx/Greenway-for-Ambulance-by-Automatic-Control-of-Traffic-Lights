#include<LiquidCrystal.h> 
//liquidcrystal.h This library allows an Arduino board to 
//control LiquidCrystal displays (LCDs)
#define IR1 8
#define IR2 9
#define IR3 10
#define IR4 11
#define IR5 12
#define IR6 13
// we have used 6 IR Sensors and assigned Arduino Mega 
// pins from 8 to 13, where pin from 2 to 13 are PWM pins in mega

#define SS 3
// Sound sensor is defined to pin number 3 
// where pin no 2 & 3 are interrupt pins in mega
// PIN 2 --> Interrupt 0
// PIN 3 --> Interrupt 1

const byte interruptPin = 2;
//we declare a variable interruptpin to pin number 2 which is interrupt 0

#define R1 25
#define Y1 26
#define G1 27
#define R2 28
#define Y2 29
#define G2 30
#define R3 31
#define Y3 32
#define G3 33
#define R4 22
#define Y4 23
#define G4 24
// we declare pin 22 to 33 for Traffic LED's of Red,Yellow & green 

int count=0;
int count1=0;

const int rs = 37, en = 35, d4 = 40, d5 = 38, d6 = 36, d7 = 34;
// rs - reset
// en - enable 
// d4,d5,d6,d7 - data pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// call the lcd function() with its formal parameters declared

char item1_id[]="08533047";
// we initialize a variable with the RFID Tag code  

String message=" ";
// create a string variable to hold null value

void setup() 
// setup() function is used to first 
// tell the microcontroller which type of stream the sensors work
{
  Serial.begin(9600);
  //### Serial. begin() establishes serial communication between
  // your Arduino board and computer 

  //### serial.begin() is used when you want to output some information 
  //from your Arduino to your computer screen.
  
  //### 9600 number is called the baud rate.
  //The baud rate signifies the data rate in bits per second. 
  //The default baud rate in Arduino is 9600 bps (bits per second).

  Serial3.begin(9600);

  //The Arduino Mega has three additional serial ports: 
  //Serial1 on pins 19 (RX) and 18 (TX), 
  //Serial2 on pins 17 (RX) and 16 (TX), 
  //Serial3 on pins 15 (RX) and 14 (TX).


  lcd.begin(16, 2);
  // lcd used is 16*2 matrix so we use it to establish connection with the arduino

  pinMode(interruptPin, INPUT_PULLUP);

  //Pinmode() is used for digital pins in arduino 
  // to either read data from sensor or to write. 

  //When you set the mode to INPUT_PULLUP, an internal resistor – inside the Arduino board 
  // it will be set between the digital pin 4 and VCC (5V). 
  // This resistor – value estimated between 20k and 50k Ohm – 
  // it will make sure the state stays HIGH. 
  // When you press the button, the states becomes LOW.


  // here interruptPin is set with INPUT_PULLUP configuration
  // i.e. when there is any change in value of InteruptPin then the state of it changes

  attachInterrupt(digitalPinToInterrupt(interruptPin), COUNT, FALLING);
//Syntax -- attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);

//###digitalPinToInterrupt(pin): In Arduino mega interrfupt pins are 2,3,18,19,20,21. 
// It Specify the input pin that is used for external interrupt here.

// ISR - It is a function that is called when an external interrupt is done.

// Mode- Type of transition to trigger on, e.g. falling, rising, etc.

//    RISING:  To trigger an interrupt when the pin transits from LOW to HIGH.
//    FALLING: To trigger an interrupt when the pin transits from HIGH to LOW.
//    CHANGE: To trigger an interrupt when the pin transits from LOW to HIGH or HIGH to LOW
  
  
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
  pinMode(IR6,INPUT);
  pinMode(SS,INPUT);
//IR sensors are Input receiving sensors. 

  pinMode(R1,OUTPUT);
  pinMode(Y1,OUTPUT);
  pinMode(G1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(Y2,OUTPUT);
  pinMode(G2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(Y3,OUTPUT);
  pinMode(G3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(Y4,OUTPUT);
  pinMode(G4,OUTPUT);
// LEDs are output sensors
  
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(G4,LOW);

  // digitalwrite is used here to set the initial output of the LED sensors

  lcd.setCursor(0,0);
  //setting cursor 0,0 matrix position
  lcd.print("GREENWAY FOR");
  // this line is printed on the first row
  lcd.setCursor(0,1);
  // now setting the cursor to 2nd row
  lcd.print("AMBULANCE");
  // this line is printed on the second row
  delay(2000);
  //delay of 2s (1000 = 1s)
}

void loop() 

{
  LANE1();
  LANE2();
  LANE3();
  LANE4();
}
void LANE1()
// 1st LANE is set to pin no's 25,26,27 on mega for R,Y & G signal
{
  for(int i=25;i<=27;i++)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    //pin 25 is made high & made low first (RED)
    //pin 26 is made high & made low second (YELLOW)
    //pin 27 is made high & then low third (GREEN) 
  }
  digitalWrite(25,HIGH);
  // after one cycle the lane signal is set back to RED

}
void LANE2()
// 2nd LANE is set to pin no's 28,29,30 on mega for R,Y & G signal
{
  for(int i=28;i<=30;i++)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
  digitalWrite(28,HIGH);
}
void LANE3()
// 3rd LANE is set to pin no's 31,32,33 on mega for R,Y & G signal
{
  for(int i=31;i<=33;i++)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
  digitalWrite(31,HIGH);

}
void LANE4()
// 4th LANE is set to pin no's 22,23,24 on mega for R,Y & G signal
{
  for(int i=22;i<=24;i++)
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
  digitalWrite(22,HIGH);
}


void COUNT(){
  count=1;
  Serial.print(count);
  
  if(count==1)
  {
    lcd.clear();
    sound();
    lcd.setCursor(0,0);
    lcd.print("EMERGENCY");
    lcd.setCursor(0,1);
    lcd.print("PLEASE GIVE WAY");
    }
    while(digitalRead(3)==1);
    lcd.clear();
    if(digitalRead(IR6)==0)
    {
      lcd.clear();
      sound1();
    }
    while(digitalRead(IR5)==0);
    if(digitalRead(IR5)==1)
    {
      loop();
    }
  }

void sound() 
//making lane 1 green
{
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(G4,LOW);
  digitalWrite(R1,LOW);
  digitalWrite(G1,HIGH);
}
void sound1() 
//making lane 4 green
{
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(G4,HIGH);
  digitalWrite(G1,LOW);
}
