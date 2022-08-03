/*
#include "ESP8266WiFi.h"

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password
*/

long duration;
int distance;
const int pinBuzzer = 10;
const int pinPower = 12;

void setup()
{
  pinMode(pinPower,OUTPUT);
  pinMode(pinBuzzer, OUTPUT); 
  pinMode (11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  Serial.begin (9600);
  
  /*
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
  */
}

void loop()
{
 digitalWrite(12,HIGH);
 digitalWrite(5,LOW);
 delayMicroseconds(2);
 digitalWrite (5,HIGH);
 delayMicroseconds(10);
 digitalWrite (5,LOW);
  
  
  
 duration = pulseIn (4,HIGH);
 
 distance = duration*0.034/2;
  
 Serial.print ("Distance: ");
 Serial.print (distance);
 Serial.println ("cm");
 
 //digitalWrite(pinBuzzer,LOW);
 //code
  
 if (distance<=100){
    tone (pinBuzzer,200,100);
   delay(10);
   digitalWrite (11,HIGH);
 }else if (100<distance<=150){
   tone (pinBuzzer,400,100);
   delay(10);
    digitalWrite (11,LOW);
 }else if (150<distance<=200){
  tone (pinBuzzer,600,100);
   delay(10);
    digitalWrite (11,LOW);
 }else if (200<distance<=250){
    tone (pinBuzzer,800,100);
    digitalWrite (11,LOW);
    delay(10);
  }else if(distance < 250){
   //digitalWrite(pinBuzzer, LOW);
   tone (pinBuzzer,LOW);
   noTone(pinBuzzer);
   delay(10);   
   digitalWrite (11,LOW);
 }
 
  /*
  //new code
   if(distance < 100){
     digitalWrite (11,HIGH);
     while(true){
       
     digitalWrite(pinBuzzer,HIGH);
     delay(0.00000001);
     digitalWrite(pinBuzzer,LOW);
     delay(0.00000001);
   
       if( distance >= 100 ){
        digitalWrite(pinBuzzer, LOW);
         digitalWrite (11,LOW);
       	break;
       }
       
     }
   }else{
    
     digitalWrite(pinBuzzer,LOW);
     digitalWrite(11,LOW);
     delay(10);
     
   }*/
}

