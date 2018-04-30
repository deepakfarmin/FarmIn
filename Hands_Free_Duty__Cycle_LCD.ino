 
 /*
 *  Author: Deepak Reddy
 *  Version : v1.0
 *  Edited on : 03/18/2018
 */
 
// include libraries

#include "PROGMEM_readAnything_.h"
#include "LiquidCrystal.h"
#include "Keypad.h"

// End of include libraries


const uint8_t NUMBER_OF_ELEMENTS = 216;

 // Creating lookup table using ProgMEM
    const PROGMEM uint8_t PwmDutyCycle[]  {
 // 0   1    2   3     4    5    6    7    8   9    10   11   12   13   14   
  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,    // 1
  55,  56,  57,  58,  59,  60,  61,  62,  64,  65,  66,  63,  67,  68,  69,    // 2
  70,  71,  72,  73,  74,  75,  76,  78,  77,  79,  80,  81,  82,  83,  84,    // 3
  85,  86,  89,  87,  90,  88,  91,  92,  93,  94,  95,  96,  97,  98,  99,    // 4
  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,   // 5
  115, 116, 117, 118, 119, 120, 121, 123, 122, 124, 125, 126, 127, 128, 129,   // 6
  130, 131, 133, 134, 132, 135, 136, 137, 138, 139, 140, 141, 142, 145, 143,   // 7
  144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,   // 8
  160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174,   // 9 
  175, 177, 179, 178, 176, 180, 181, 182, 183, 184, 185, 186, 187, 188, 191,   // 10
  189, 190, 192, 193, 194, 195, 196, 199, 197, 198, 200, 202, 201, 203, 205,   // 11
  206, 204, 207, 208, 209, 211, 210, 212, 213, 214, 215, 216, 217, 218, 219,   // 12 
  220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234,   // 13
  235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249,   // 14 
  250, 251, 252, 253, 254, 255                                                 // 15
  };


  const PROGMEM int DeltaPulse[]  {
 // 0    1     2     3     4     5     6     7     8     9    10    11    12    13    14        
  393,  407,  425,  456,  468,  488,  514,  533,  559,  593,  629,  650,  682,  699,  723,     // 1
  755,  760,  807,  837,  891,  902,  916,  939,  977,  990,  995,  999,  1027, 1066, 1071,    // 2
  1085, 1097, 1132, 1164, 1175, 1207, 1278, 1337, 1343, 1352, 1380, 1408, 1434, 1442, 1466,    // 3
  1497, 1521, 1552, 1553, 1578, 1586, 1594, 1620, 1643, 1668, 1709, 1727, 1764, 1789, 1798,    // 4
  1829, 1869, 1894, 1916, 1917, 1949, 1954, 1976, 1998, 2015, 2031, 2054, 2086, 2113, 2131,   // 5
  2161, 2173, 2213, 2234, 2244, 2271, 2312, 2339, 2351, 2371, 2384, 2412, 2433, 2444, 2459,    // 6
  2496, 2550, 2554, 2558, 2562, 2586, 2614, 2641, 2672, 2694, 2724, 2767, 2799, 2820, 2823,   // 7
  2825, 2851, 2867, 2899, 2903, 2958, 2977, 3016, 3051, 3148, 3171, 3191, 3221, 3240, 3255,   // 8
  3284, 3294, 3305, 3326, 3334, 3353, 3363, 3398, 3430, 3452, 3480, 3485, 3493, 3512, 3575,    // 9
  3601, 3640, 3642, 3644, 3646, 3691, 3704, 3712, 3732, 3738, 3760, 3767, 3812, 3891, 3922,    // 10
  3929, 3933, 3938, 3972, 3997, 4061, 4062, 4115, 4134, 4135, 4170, 4186, 4196, 4214, 4262,   // 11 
  4281, 4294, 4299, 4320, 4339, 4403, 4421, 4451, 4488, 4518, 4555, 4577, 4581, 4620, 4683,    // 12
  4684, 4687, 4708, 4727, 4760, 4825, 4834, 4842, 4865, 4894, 4901, 4922, 4931, 4943, 4966,   // 13
  4979, 4995, 5098, 5113, 5114, 5120, 5133, 5212, 5234, 5291, 5298, 5325, 5351, 5363, 5363,  // 14
  5397, 5449, 5492, 5527, 5537, 5550   // 15  
};

// end of lookup table

const uint8_t ROWS= 4; //number of rows on the keypad i.e. 4
const uint8_t COLS= 4; //number of columns on the keypad i,e, 4

//define the symbols on the buttons of the keypads
const char keys[ROWS][COLS] = {
   {'1', '2', '3', 'Y'},
   {'4', '5', '6', 'N'},
   {'7', '8', '9', 'B'},
   {'R', '0', '.', 'E'}
};
//end of define symbols 

 // Assigning Pins
 
 //Interrupts
 const uint8_t REF_MOTOR_ENCODER = 18;  //Input from Reference Motor Encoder
 const uint8_t SHAFT_MOTOR_ENCODER = 21;  // Input from Shaft Motor Encoder

// PWM Outputs
 const uint8_t SHAFT_MOTOR_PWM = 6;  // PWM Output
 const uint8_t REF_MOTOR_PWM = 8;   // PWM Output

// Digital I/O 
LiquidCrystal lcd(35,33,31,29,27,25);

const uint8_t rowPins[ROWS] = {38, 36, 34, 32}; //connect to the row pinouts of the keypad
const uint8_t colPins[COLS] = {30, 28, 26, 24}; //connect to the column pinouts of the keypad

 const uint8_t RELAY = 40;
 
 const uint8_t REF_MOTOR_ENCODER_LED = 45;
 const uint8_t SHAFT_MOTOR_ENCODER_LED = 49; 
  
 // end of Assiging Pins 
 
 Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
 
 // Initializing Variables 
 volatile unsigned int RefMotorEncoderPulses;       // Intializing Reference Motor Encoder Pulses
 volatile unsigned int ShaftMotorEncoderPulses ;     // Intializing Shaft Motor Encoder Pulses
 volatile unsigned long PreviousMillis;    
 volatile unsigned long ShaftEncoderPulsePeriod;        
 volatile unsigned int PreviousRefMotorPulses; 
 const float mmTofeet = 1.0/304.8;                       // Conversion of mm to feet
 volatile uint8_t ShaftMotorDutyCycle = 125;          // Setting PWM output duty cycle for Shaft Motor
 volatile float VehicleSpeed;
 volatile bool StartTimer = false;
 volatile float DesiredShaftPulsePerSec;
 volatile unsigned long CurrentShaftMotorPulsePerSec;
 //volatile bool SendPWM = false; 
 const int interval = 1000;
uint8_t WheelNumber;
uint8_t SeedSpacing;
char* displayString[] =  {"Enter Wheel No", "Seed distance"};
uint8_t strgindex = 0; 
 
// emd of Initializing Variables

// Getting number from Keypad
int GetNumber()
 {
   int num = 0;
   char key = myKeypad.getKey();
   lcd.setCursor(0,0);
   lcd.print(displayString[strgindex]);
   lcd.setCursor(1,1);
   while(key != 'E')
   {
   
    
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            lcd.print(key);
            num = num * 10 + (key - '0');
            break;

         case 'B':
            num = 0;
            lcd.clear();
             lcd.setCursor(0,0);
            lcd.print(displayString[strgindex]);
            lcd.setCursor(1,1);
            break;
      }

      key = myKeypad.getKey();
   }

   return num;
  
 }

// Getting User Input
 void GetUserInput()
 {
  
  int displayinterval = 1000;
  unsigned long StartTime = millis();
  lcd.print("Hello");
  delay(displayinterval);
  lcd.clear();
  //lcd.print("Enter Wheel No");
  
  WheelNumber = GetNumber();
  // Confirm Wheel
   strgindex++;
  lcd.clear();
  SeedSpacing = GetNumber();
   lcd.clear();
  //confirm SeedSpacing  
 }
 
 
// Finding Speed of Vehicle
 void toggleWheelSpeed()
 {
   static const int WheelDiameter = 250;                 // measured in mm. change from int to float if diameter is in decimel.
   static const float pi = 3.14159;
   static const float LinearDistance = pi*(float)WheelDiameter;                     // Circumference in mm.
   static const int REF_MOTOR_ENCODER_CPR = 10;                                   // No of Pulses Per Revoulution
   static const float DistanceInOneTick = LinearDistance*mmTofeet/(float)REF_MOTOR_ENCODER_CPR;   //  Distance covered in feet in single Tick
   float RefMotorPulsePerSec = float(RefMotorEncoderPulses - PreviousRefMotorPulses)*1000.0/(float)interval;   // Pulses Per Second
   VehicleSpeed = RefMotorPulsePerSec*DistanceInOneTick;   // Speed in feets per second
    if (VehicleSpeed == 0)
    {
      ShaftMotorDutyCycle = 0;
      analogWrite(SHAFT_MOTOR_PWM, ShaftMotorDutyCycle);
      StartTimer = false;
      digitalWrite(RELAY, LOW);
    }
     
 }
// End of toggleWheelSpeed
 

// Determining the value of PWM between 0 - 255
void ChangeDutyCycle()
{
  static const uint8_t SeedWheelTeeth = WheelNumber;
  static const uint8_t SeedWidth = SeedSpacing;    //distance in feets
        Serial.print("\n");
        Serial.print("Teeth");
        Serial.print("\t");
        Serial.print("\t");
        Serial.print(SeedWheelTeeth);
         Serial.print("\n");
        Serial.print("Spacing");
        Serial.print("\t");
        Serial.print("\t");
        Serial.print(SeedSpacing);
  
  static const int SHAFT_MOTOR_ENCODER_CPR = 36;
  static const float PulsesPerTeeth = (float)SHAFT_MOTOR_ENCODER_CPR/(float)SeedWheelTeeth;
  float SeedRate = VehicleSpeed/(float)SeedWidth;
  DesiredShaftPulsePerSec = PulsesPerTeeth*SeedRate;
  
  // Finding index of PWM value 
  uint8_t k;
  uint8_t kdx = 0; // default index of first element
  int DeltaPulsePerMin;
  PROGMEM_readAnything(&DeltaPulse[kdx], DeltaPulsePerMin);
  float InitialPulsePerSec = (float) DeltaPulsePerMin/60.0;
  float InitialDifference = abs(InitialPulsePerSec - DesiredShaftPulsePerSec);
  for (size_t k = 1; k < NUMBER_OF_ELEMENTS; k++)
  {
    int DeltaPulsePerMin;
    PROGMEM_readAnything(&DeltaPulse[k], DeltaPulsePerMin);
    float NextPulsePerSec = (float) DeltaPulsePerMin/60.0 ;
    float FinalDifference = abs(NextPulsePerSec - DesiredShaftPulsePerSec);
    if (FinalDifference >= InitialDifference)
     {
        kdx = k-1;
        break;
     }
     InitialDifference = FinalDifference;
  }
  uint8_t GetPWM;
  PROGMEM_readAnything(&PwmDutyCycle[kdx], GetPWM);
  ShaftMotorDutyCycle = GetPWM;   
  
  //SendPWM = true;
  
}
// end of ChangeDutyCycle



void toggleSendPWM()
{
  analogWrite(SHAFT_MOTOR_PWM, ShaftMotorDutyCycle);
}
 
void setup() 
{
  
 // Reference Motor encoder setup
  pinMode(REF_MOTOR_ENCODER_LED,OUTPUT);
  pinMode(REF_MOTOR_ENCODER, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(REF_MOTOR_ENCODER), CountRefMotorEncoderPulses, CHANGE);

//  Shaft Motor Encoder Setup
  pinMode(SHAFT_MOTOR_ENCODER_LED, OUTPUT);
  pinMode(SHAFT_MOTOR_ENCODER, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SHAFT_MOTOR_ENCODER), CountShaftMotorEncoderPulses, RISING);

// Motor PWM Pins 
  pinMode(REF_MOTOR_PWM, OUTPUT);
  pinMode(SHAFT_MOTOR_PWM, OUTPUT);
  pinMode(RELAY, OUTPUT);

// Changing PWM frequency to 31KHz on PIns 5 and 3
  TCCR4B = (TCCR4B & 0b11111000) | 0x01; 
  
 // set up the LCD's number of columns and rows:
 lcd.begin(16, 2);
  GetUserInput();
  Serial.begin(115200);
  

}

void loop() 
{
//   Serial.print("\n");
//        Serial.print("loop running");
//        
  if (Serial.available())
  {
        Serial.print("\n");
        Serial.print("Available");
        Serial.print("\t");
        Serial.print("\t");
        Serial.print(millis());
            
    int speed = Serial.parseInt();
    if (speed > 0 && speed <= 255)
    {
      Serial.print("\n");
        Serial.print("Speed");
        Serial.print("\t");
        Serial.print("\t");
        Serial.print(speed);
      digitalWrite(RELAY, HIGH);
      analogWrite(REF_MOTOR_PWM, speed);
      
      if (StartTimer == false)
      {
        PreviousMillis = millis();
        analogWrite(SHAFT_MOTOR_PWM, ShaftMotorDutyCycle);
        StartTimer = true;
        Serial.print("\n");
        Serial.print("Start");
        Serial.print("\t");
        Serial.print("\t");
        Serial.print(StartTimer);
      }
    }
      else
       {
           Serial.print("\n");
        Serial.print("RELAY LOW");
       digitalWrite(RELAY, LOW);
       }
 } 
      
      if (((millis() - PreviousMillis) >= interval) && (StartTimer == true))
      {
        Serial.print("\n");
        Serial.print("Measuring Speed");
        noInterrupts();
        toggleWheelSpeed();
        ChangeDutyCycle();
        toggleSendPWM();
        interrupts();
        PreviousMillis = millis();
        PreviousRefMotorPulses = RefMotorEncoderPulses;
     //   PreviousShaftMotorPulses = ShaftMotorEncoderPulses;        
      }
}

  

// ISR Referencce Motor Encoder
 void CountRefMotorEncoderPulses()
 {
  RefMotorEncoderPulses++;
 }

// ISR Shaft Motor Encoder
  void CountShaftMotorEncoderPulses()
 {
 // static unsigned long PreviousMicros = 0;
  //unsigned long ShaftEncoderTime = micros();
  ShaftMotorEncoderPulses++;
  //ShaftEncoderPulsePeriod = (ShaftEncoderTime - PreviousMicros);
  //PreviousMicros = ShaftEncoderTime;
 }


