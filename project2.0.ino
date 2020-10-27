#include "pins_arduino.h"
int device1 = 3;
int device2 = 5;
int device3 = 9;
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 4; //Echo pin of 1st Sesnor
const int trigger2 = 6; //Trigger pin of 2nd Sesnor
const int echo2 = 8;//Echo pin of 2nd Sesnor


long time_taken;
int dist;
int x;
int y;
int count=0;
int value=25;
void setup() {
Serial.begin(9600); 

pinMode(device1, OUTPUT); // device 1

pinMode(device2, OUTPUT); // device 2

pinMode(device3, OUTPUT); // device 3

pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;

}

void brightness_up( int device)
{ 
  while(value>=0 && value<=250)
  {
    value=value+25;
  analogWrite(device,value);
 }
}

void brightness_down( int device)
{ 
  while(value>=0 && value<=250)
  {
    value=value-25;
  analogWrite(device,value);
 }
}



void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
x =dist; //get distance of x sensor

calculate_distance(trigger2,echo2);
y =dist; //get distance of y sensor

if(y>7 && y<20)
{
  while((y>7 && y<20)) //Detect x-axis

 {count=count+1;
  if(count==1)
 {Serial.println ("toggle 1"); delay (300);
 digitalWrite(device1, HIGH); 
 digitalWrite(device2, LOW);
 digitalWrite(device3, LOW);
 }

if(count==2)
 {Serial.println ("toggle 2"); delay (300);
 digitalWrite(device1, LOW); 
 digitalWrite(device2, HIGH);
 digitalWrite(device3, LOW);
  
 }

 if(count==3)
 {Serial.println ("toggle 3"); delay (300);
digitalWrite(device1, LOW); 
 digitalWrite(device2, LOW);
 digitalWrite(device3, HIGH);
 }

 else
 count=0;
 }
 }

calculate_distance(trigger1,echo1);
x =dist;

calculate_distance(trigger2,echo2);
y =dist;



 if ((x>y))//Detect y-axis
{   while(x<=40)
    {
      calculate_distance(trigger1,echo1);
      x =dist;
      if (x>4 && x<12) //Hand pulled up
      {  
        if(device1==HIGH)
        {brightness_up(device1);
        delay (300);}
         
         if(device2==HIGH)
        {brightness_up(device2);
        delay (300);}
          
          if(device3==HIGH)
        {brightness_up(device3);
        delay (300);}
      }
      if (x>13 && x<23) //Hand pulled down
      {
        if(device1==HIGH)
        {brightness_down(device1);
        delay (300);}
         
         if(device2==HIGH)
        {brightness_down(device2);
        delay (300);}
          
          if(device3==HIGH)
        {brightness_down(device3);
        delay (300);}
      
    }
  }
}


calculate_distance(trigger1,echo1);
x =dist;

calculate_distance(trigger2,echo2);
y =dist;

 

 if ((x/y==1))//Detect diagonal
{   while(x<=20 && y<=20)
    {
      Serial.println ("Diagonal"); delay (300);
    }
  }
 

calculate_distance(trigger1,echo1);
x =dist;

calculate_distance(trigger2,echo2);
y =dist;
 
 

   delay(100);
   
}
