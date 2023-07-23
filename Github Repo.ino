int IR1 = A0;
int IR2 = A1;
int IR3 = A2;
int IR4 = A3;
int IR5 = A4;

int enB = 9; // Right motor
int MotorAip1 = 7;
int MotorAip2 = 6;
// motor two
int enA = 3; // Left motor
int MotorBip1 = 5;
int MotorBip2 = 4;

void stop()
{
  // Stop both Motors
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void move()
{
  // Move both the Motors
  digitalWrite(MotorAip1, 0);
  digitalWrite(MotorAip2, 1);
  digitalWrite(MotorBip1, 1);
  digitalWrite(MotorBip2, 0);
  analogWrite(enA, 40);
  analogWrite(enB, 40);
}
void moveleft()
{
  digitalWrite(MotorAip1, 0);
  digitalWrite(MotorAip2, 1);
  digitalWrite(MotorBip1, 0);
  digitalWrite(MotorBip2, 1);
  analogWrite(enA, 38);
  analogWrite(enB, 48);
}

void Left()
{
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  analogWrite(enA, 30);
  analogWrite(enB, 50);
}

void Leftmax()
{
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  analogWrite(enA, 30);
  analogWrite(enB, 50);
}

void moveright()
{
  digitalWrite(MotorAip1, HIGH); // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
  analogWrite(enB, 38);
  analogWrite(enA, 48);
}

void Right()
{
  digitalWrite(MotorAip1, HIGH); // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  analogWrite(enA, 50);
  analogWrite(enB, 30);
}

void Rightmax()
{
  digitalWrite(MotorAip1, HIGH); // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
  analogWrite(enA, 50);
  analogWrite(enB, 3);
}

void R()
{
  move();
  delay(600);
  Rightmax();
  delay(550);
}

void Ri()
{
  move();
  delay(750);
  Rightmax();
  delay(775);
}

void L()
{
  move();
  delay(600);
  Leftmax();
  delay(550);
}


void Li()
{
  move();
  delay(750);
  Leftmax();
  delay(775);
}
void U()
{
  Leftmax();
  delay(1050);
  stop();
}
void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
}

void loop()
{
    if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && digitalRead(IR3) == HIGH && digitalRead(IR4) == HIGH && digitalRead(IR5) == HIGH)
  {
    // IR not on black line
    Serial.println("Turn Left");
    moveleft();
    delay(500);
    if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && digitalRead(IR3) == HIGH && digitalRead(IR4) == HIGH && digitalRead(IR5) == HIGH)
    stop();


  }
  
  if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && digitalRead(IR3) == HIGH && digitalRead(IR4) == LOW && digitalRead(IR5) == LOW)
  {
    // IR not on black line
    Serial.println("Turn Right");
    move();
  }
  
  if (digitalRead(IR1) == HIGH && digitalRead(IR2) == LOW && digitalRead(IR3) == LOW && digitalRead(IR4) == LOW && digitalRead(IR5) == LOW)
  {
    // IR not on black line
    Serial.println("Turn Left");
    moveleft();
  }
  if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && digitalRead(IR3) == LOW && digitalRead(IR4) == LOW && digitalRead(IR5) == LOW)
  {
    // IR not on black line
    Serial.println("Turn Left");
    moveleft();
  }
  if (digitalRead(IR1) == HIGH && digitalRead(IR2) == HIGH && digitalRead(IR3) == HIGH && digitalRead(IR4) == LOW && digitalRead(IR5) == LOW)
  {
    // IR not on black line
    Serial.println("Turn Left");
    moveleft();
  }
  if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && digitalRead(IR3) == LOW && digitalRead(IR4) == LOW && digitalRead(IR5) == HIGH)
  {
    // IR not on black line
    Serial.println("Turn Right");
    moveright();
  }
  if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && digitalRead(IR3) == LOW && digitalRead(IR4) == HIGH && digitalRead(IR5) == HIGH)
  {
    // IR not on black line
    Serial.println("Turn Right");
    moveright();
  }
  if (digitalRead(IR1) == LOW && digitalRead(IR2) == LOW && digitalRead(IR3) == HIGH && digitalRead(IR4) == HIGH && digitalRead(IR5) == HIGH)
  {
    // IR not on black line
    Serial.println("Turn Right");
    moveright();
  }

}
