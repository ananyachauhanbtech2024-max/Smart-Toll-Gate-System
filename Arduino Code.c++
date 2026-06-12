#include <Servo.h>

Servo gate;

int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gate.attach(6);

  gate.write(0);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 15)
  {
    gate.write(90);
    delay(3000);
    gate.write(0);
  }

  delay(500);
}
