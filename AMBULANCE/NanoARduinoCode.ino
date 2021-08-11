#include <SoftwareSerial.h>
SoftwareSerial nanoserial(5,6);
SoftwareSerial nanoserial1(7,8);
#define SS 2
#define T 3
#define T1 4
char item1_id[]="08533047";
String message=" ";
//char item1_id1[]="08533047";
//String message1=" ";
void setup() 
{
  Serial.begin(9600);
  nanoserial.begin(9600);
  nanoserial1.begin(9600);
  pinMode(SS,INPUT);
  pinMode(T,OUTPUT);
  pinMode(T1,OUTPUT);
}
void loop() 
{
  if(digitalRead(SS)==0)
  {
    while(nanoserial.available()==0);
    if(nanoserial.available()>0)
    {
     message=nanoserial.readString();
     Serial.println(message);
     int str_len = message.length();
     char textmessage[8];
     message.toCharArray(textmessage,str_len);
     textmessage[8]='\0';
     if(strcmp(textmessage,"08533047")==0)
     {
        digitalWrite(T,LOW);
        delay(1000);
        digitalWrite(T,HIGH);       
     }
     while(nanoserial1.available()==0);
     if(nanoserial1.available()>0)
    {
     message1=nanoserial1.readString();
     Serial.println(message1);
     int str_len = message1.length();
     char textmessage1[11];
     message.toCharArray(textmessage1,str_len);
     textmessage1[11]='\0';
     if(strcmp(textmessage1,"$000853304")==0)
     {
        digitalWrite(T1,LOW);
        delay(1000);
        digitalWrite(T1,HIGH);       
     }
    }
    } 
  }
}
