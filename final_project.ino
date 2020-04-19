#include <Servo.h>
//Servo servo; //create a servo object to control a servo

int haveZombies = 0;
int needSecondDefense = 0;

const int trigPin = 2;
const int echoPin = 3;
const int bubbleMotor = 5;
const int musicMotor = 6;

long duration;
int distance;
int pos = 0;

void setup()
{
  //servo.attach(8);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(bubbleMotor, OUTPUT);
  
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
    needSecondDefense = needSecondDefense + 1;
  } else {
    haveZombies = 0;
  }
  
  if (haveZombies == 1) {
    firstDefense();
  }

  if (needSecondDefense == 10) {
    secondDefense();
  }

}

void firstDefense() 
{
  Serial.println("first defense");
  digitalWrite(bubbleMotor, HIGH);
  delay(100 0);
  digitalWrite(bubbleMotor, LOW);
  delay(800);

}

void secondDefense() 
{
  Serial.println("second defense");
  digitalWrite(musicMotor, HIGH);
  delay(1000);
  digitalWrite(musicMotor, LOW);
  delay(1000);
}



