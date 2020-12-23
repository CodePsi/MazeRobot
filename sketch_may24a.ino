int sensorL = 0;
int sensorF = 0;
int sensorR = 0;

int spd = 85;

void setup() {
  // put your setup code here, to run once:
  for (int i = 5; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorL = analogRead(5);
  sensorF = analogRead(6);
  sensorR = analogRead(7);

  if (sensorL > 200 && sensorL < 700 && sensorR > 200 && sensorR < 700 && sensorF < 500) {
    if (sensorL < sensorR - 10) {
      forward();
      analogWrite(10, spd-10);
      analogWrite(5, spd);
      Serial.print("right");
    } else {
      forward();
      analogWrite(10, spd);
      analogWrite(5, spd-10);
      Serial.print("left");
    }
  } else if (sensorF > 500) {
    if (sensorL < sensorR - 10) {
      right();
      analogWrite(10, spd);
      analogWrite(5, spd);
      while(sensorF > 400){
        sensorF = analogRead(6);
        sensorR = analogRead(7);
        sensorL = analogRead(5);
      }
      forward();
      delay(100);
      Serial.print("right");
      //delay(120);
      forward();
    } else {
      left();
      analogWrite(10, spd);
      analogWrite(5, spd);
      while(sensorF > 400 ){
        sensorF = analogRead(6);
        sensorL = analogRead(5);
        sensorR = analogRead(7);
      }
      forward();
      delay(100);
      Serial.print("left");
      //delay(120);
      forward();
    }
  }
  Serial.print(sensorL);
  Serial.print("\t");
  Serial.print(sensorF);
  Serial.print("\t");
  Serial.println(sensorR);

  delay(20);
}

void right() {//forward
   
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void left() {//backward
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void backward() {//left
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void forward() {//right 
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void stp() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}