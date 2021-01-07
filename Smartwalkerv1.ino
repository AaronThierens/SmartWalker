/* with this code you can make a walker smart: which means the walker can see obstacles and give feedback to the 'driver'. This concept is developed in cooperation with a deafblind man and howest university of applied sciences.
 *  The students who worked on this projects are : Dubois Simon, Maes Bernd and Thierens Aaron
 */

#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter(0x23);

const int Triggerpinvooraan = 10;//9
const int Echopinvooraan = 9;//10

const int Triggerpinlinks = 5;//5
const int Echopinlinks = 6;//6

const int Triggerpinrechts = 7;
const int Echopinrechts = 8;

const int Feedbacklinks = 12;
const int Feedbackrechts = 2;

const int LEDs_rood = 3;
const int LEDs_wit = 4;

long duration;
int distance =0;

long durationlinks;
int distancelinks =0;

long durationrechts;
int distancerechts =0;

void setup() {
  pinMode(Triggerpinvooraan, OUTPUT);
  pinMode(Echopinvooraan, INPUT);
  
  pinMode(Triggerpinlinks, OUTPUT);
  pinMode(Echopinlinks, INPUT);
  
  pinMode(Triggerpinrechts, OUTPUT);
  pinMode(Echopinrechts, INPUT);
  
  pinMode(Feedbacklinks, OUTPUT);
  pinMode(Feedbackrechts, OUTPUT);
  
  Serial.begin(9600);
  Wire.begin();
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }

}

void loop() {
  long durationvooraan, distancevooraan;
  digitalWrite(Triggerpinvooraan, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(Triggerpinvooraan, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(Triggerpinvooraan, LOW);
  durationvooraan = pulseIn(Echopinvooraan, HIGH);
  distancevooraan = (durationvooraan/2) / 29.1;

    Serial.print ( "Sensor1  ");
    Serial.print ( distancevooraan);
    Serial.println("cm");
    if (distancevooraan<120){
      if (distancevooraan<90){
        if (distancevooraan<50){
        digitalWrite(Feedbacklinks, HIGH);
        digitalWrite(Feedbackrechts, HIGH);
        delay(100);
        digitalWrite(Feedbacklinks, LOW);
        digitalWrite(Feedbackrechts, LOW);
        delay(100);
       }
      else {
        digitalWrite(Feedbacklinks, HIGH);
        delay(200);
        digitalWrite(Feedbacklinks, LOW);
        digitalWrite(Feedbackrechts,HIGH);
        delay(200);
        digitalWrite(Feedbackrechts, LOW);
        delay(200);
      }
    }
    else {
      digitalWrite(Feedbacklinks, HIGH);
      digitalWrite(Feedbackrechts,HIGH);
    }
  }
     else {
      digitalWrite(Feedbacklinks && Feedbackrechts, LOW);
    }


long durationlinks, distancelinks;
  digitalWrite(Triggerpinlinks, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(Triggerpinlinks, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(Triggerpinlinks, LOW);
  durationlinks = pulseIn(Echopinlinks, HIGH);
  distancelinks= (durationlinks/2) / 29.1;
    Serial.print("Sensor2  ");
    Serial.print(distancelinks);
    Serial.println("cm");
   if (distancelinks<40){
      if (distancelinks<30){
        if (distancelinks<15){
        digitalWrite(Feedbacklinks, HIGH);
        delay(100);
        digitalWrite(Feedbacklinks, LOW);
        delay(100);
       }
      else {
        digitalWrite(Feedbacklinks, HIGH);
        delay(200);
        digitalWrite(Feedbacklinks, LOW);
        delay(200);
      }
    }
    else {
      digitalWrite(Feedbacklinks, HIGH);
    }
  }
     else {
      digitalWrite(Feedbacklinks, LOW);
    }

  
  long durationrechts, distancerechts;
  digitalWrite(Triggerpinrechts, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(Triggerpinrechts, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(Triggerpinrechts, LOW);
  durationrechts = pulseIn(Echopinrechts, HIGH);
  distancerechts= (durationrechts/2) / 29.1;
    Serial.print("Sensor3  ");
    Serial.print(distancerechts);
    Serial.println("cm");
    Serial.println("*******");
    if (distancerechts<40){
      if (distancerechts<30){
        if (distancerechts<15){
        digitalWrite(Feedbackrechts, HIGH);
        delay(100);
        digitalWrite(Feedbackrechts, LOW);
        delay(100);
       }
      else {
        digitalWrite(Feedbackrechts, HIGH);
        delay(200);
        digitalWrite(Feedbackrechts, LOW);
        delay(200);
      }
    }
    else {
      digitalWrite(Feedbackrechts, HIGH);
    }
  }
     else {
      digitalWrite(Feedbackrechts, LOW);
    }



}
