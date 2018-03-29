 echo "# FarmIn" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/deepakfarmin/FarmIn.git
git push -u origin master
 
 /*
 *  Author: Deepak Reddy
 *  Version : v1.0
 *  Edited on : 03/18/2018
 */
#include "ASD.h"

/*
 * KeyPad INput Variables
 * LCD output variables
 */

  
 volatile unsigned int GroundWheelEncoderTicks = 0;  // Defining Ground Wheel Encoder Values
 volatile unsigned int ShaftOneEncoderTicks = 0;     // Defining Shaft One Encoder Values
  //volatile unsigned long ShaftTwoEncoderTicks = 0;  // Defining Shaft Two Encoder Values
 volatile unsigned long PreviousTime = 0;            // Time from start of the Program
 const float inchTofeet = 1/12.0;              // Conversion of inches to feet
 const float mmTofeet = 1/304.8;
 volatile uint8_t ShaftOneDutyCycle = 125;          // Setting PWM output duty cycle for First Shaft Motor
// volatile uint8_t ShaftTwoDutyCycle = 125;          // Setting PWM output duty cycle for Second Shaft Motor
 
void setup() 
{
 
    Serial.begin(115200);

// Ground Wheel encoder setup
  pinMode(GroundWheelEncoderLed,OUTPUT);
  pinMode(GroundWheelEncoder, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(GroundWheelEncoder), CountGroundWheelEncoderTicks, CHANGE);

//  Shaft One Encoder Setup
  pinMode(ShaftOneEncoderLed, OUTPUT);
  pinMode(ShaftOneEncoder, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ShaftOneEncoder), CountShaftOneEncoderTicks, CHANGE);

// Motor PWM Pins 
  pinMode(GroundWheelPWM, OUTPUT);
  pinMode(ShaftOnePWM, OUTPUT);
  pinMode(RELAY, OUTPUT);

// Changing PWM frequency to 31KHz on PIns 5 and 3
  TCCR3B = (TCCR3B & 0b11111000) | 0x01; 
 
     while (! Serial);
  Serial.println("Speed 0 to 255");

}

void loop() 
{
  
  if (Serial.available())
  {
     digitalWrite(RELAY, HIGH);
    int speed = Serial.parseInt();
    if (speed > 0 && speed <= 255)
    {
      analogWrite(GroundWheelPWM, speed);
      
      if (millis() - PreviousTime >= 1000)
      {
        GroundWheelSpeed();
        PreviousTime = millis();
        PreviousGWEncoderTick = GroundWheelEncoder
      }
      
   // analogWrite(MainMotorPin, speed);
    }
    else
    {
      digitalWrite(RELAY, LOW);
    }
    }
  
  

      
  Serial.print("\n"); 
  Serial.print("MT");
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print("MR");
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print("RT");
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print("RR");
  Serial.print("\t");
  Serial.print("\t");
// 
  
//  Serial.print("RPM");
//  Serial.print("\t");
//  Serial.print("\t");
  
//  Serial.print("\n");
//  
//  Serial.print(MainEncoderTicks);
//  Serial.print("\t");
//  Serial.print("\t");
//  
//  Serial.print(MainEncoderRev);
//  Serial.print("\t");
//  Serial.print("\t");
//  
//  Serial.print(RefEncoderTicks);
//  Serial.print("\t");
//  Serial.print("\t");
//
//  Serial.print(RefEncoderRev);
//  Serial.print("\t");
//  Serial.print("\t");
//
//    Serial.print(Time);
//  Serial.print("\t");
//  Serial.print("\t");
  
//  Serial.print(RPM);   
  Serial.print("\n");
  digitalWrite(GroundWheelEncoderLed,LOW);
  digitalWrite(ShaftOneEncoderLed,LOW);
  
 
  }
  

// ISR Motor Encoder
 void CountGroundWheelEncoderTicks()
 {
  digitalWrite(GroundWheelEncoderLed,HIGH);
    GroundWheelEncoderTicks++;
 }

// ISR User Encoder
  void CountShaftOneEncoderTicks()
 {
  digitalWrite(ShaftOneEncoderLed,HIGH);
  ShaftOneEncoderTicks++;
  
 }

 void GroundWheelSpeed()
 {
   static const int GroundWheelDiameter = 250;                                // measured in mm. change from int to float if diameter is in decimel.
   static const float LinearDistance = pi*GroundWheelDiamter;                     // Circumference in mm.
   static const int GroundWheelEncoderCPR = 10;                                   // No of Ticks Per Revoulution
   static const float DistanceInOneTick = LinearDistance*mmTofeet/GroundWheelEncoderCPR;   //  Distance covered in mm in single Tick
   static int GWTicksRate = GroundWheelEncoderTicks;
   
   
   
   
  
 }

