int button = 10;
int LED = 11;

int trigPin = 9;
int echoPin = 8;

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  

  if (analogRead(A0) > 700) {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  Serial.print("potentiometer: ");
  Serial.println(analogRead(A0));


  if (digitalRead(button) == HIGH){

  digitalWrite(LED, HIGH);
  } else {
  digitalWrite(LED, LOW);

  }


  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("distance away: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);

  Serial.print("button state: ");
  Serial.println(digitalRead(button));

}
