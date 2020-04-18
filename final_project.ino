#include <Servo.h>
Servo myservo; //create a servo object to control a servo

int haveZombies = 0;
int needSecondDefense = 0;

const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 8;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //begin serial communication 
}

void loop()
{
      // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2; // Prints the distance on the Serial Monitor
  if (distance < 40) {
    Serial.println("IDENTIFIED: ZOMBIE");
    haveZombies = 1;
  } else {
    haveZombies = 0;
  }
  
  if (haveZombies == 1) {
    firstDefense();
  }

  if (needSecondDefense == 1) {
    secondDefense();
  }

}

void firstDefense() 
{

}

void secondDefense() 
{

}

