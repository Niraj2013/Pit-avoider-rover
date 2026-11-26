char Bluetooth = 0;
int IRL=6;
int IRR=7;
#define LM1 2
#define LM2 3
#define RM1 4
#define RM2 5
#define EN1 9
#define EN2 10
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
}
void Forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void Backward() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void Left() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void Right() {
  digitalWrite(LM2, HIGH);
  digitalWrite(LM1, LOW);
  digitalWrite(RM2, LOW);
  digitalWrite(RM1, HIGH);
}

void Stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  IRL=digitalRead(6);
  IRR=digitalRead(7);
  analogWrite(EN1, 100);
  analogWrite(EN2, 100);
  if (IRL==0 && IRR==0){
  if (Serial.available()) {
    Bluetooth = Serial.read();

    Serial.print("I recieved - ");
    Serial.print(Bluetooth);
    if (Bluetooth == 'F') {
      Forward();
      delay(300);
      Stop();
    } else if (Bluetooth == 'B') {
      Backward();
      delay(300);
      Stop();
    } else if (Bluetooth == 'R') {
      Right();
      delay(300);
      Stop();
    } else if (Bluetooth == 'L') {
      Left();
      delay(300);
      Stop();
    } else if (Bluetooth == 'S') {
      Stop();
    }
  }
  }
  else{
    Stop();
  }
}