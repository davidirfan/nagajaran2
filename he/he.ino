#include <Servo.h>

const int trigPin=D2;
const int echoPin=D1;
const int servoPin=D3;

Servo servo;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  int degree = map(distance, 5, 100, 0, 180);
  if (degree <= 5) {
    degree = 0;
  }
  else if (degree >= 180) {
    degree = 180;
  }

  Serial.print("Degree: ");
  Serial.println(degree);
  
  servo.write(degree);

  delay(500);
}