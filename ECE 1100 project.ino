int count = 0;
int ePin = 9;
int tPin = 10;
float duration,distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(tPin,OUTPUT);
  pinMode(ePin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(tPin,LOW);
  delayMicroseconds(2);
  digitalWrite(tPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin,LOW);

  duration = pulseIn(ePin, HIGH);
  distance = duration * 0.0343 * 0.5;
  Serial.println(duration);
  Serial.println(distance);

  
  if (distance > 0 && distance < 30){
    count += 1;
  }
  else{
    count = 0;
  }

  if (count == 0){
    analogWrite(6,0);
  }
  else if (count >= 333){ // 333 approx 5 sec
    analogWrite(6,distance/30 * 255);
  }
  else{
    analogWrite(6,0);
  }
  delay(10);
}
