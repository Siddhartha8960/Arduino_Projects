

// defines pins numbers
const int trigPin = 8;

const int echoPin = 6;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication



}


void loop() {
  if(Serial>0)
  {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(10000);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10000);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance >= 25){
  //digitalWrite(buzzer, HIGH);
  tone(buzzer, 3000, 500); //buzzer pin, freq in hz, duration
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");

Serial.println(distance);
if(distance<14)
{
  //Serial.println("Braker");
  //tone(buzzer, 2500, 500); //buzzer pin, freq in hz, duration
  digitalWrite(ledPin, HIGH);
  delay(1000);
}
else if(distance<18)
{
   Serial.println("safe");
   delay(1000);
 }
 else if(distance>=18)
{
   Serial.println("Pothole");
   tone(buzzer, 3100, 500); //buzzer pin, freq in hz, duration
  digitalWrite(ledPin, HIGH);
   delay(1000);
 }
 

}
}



