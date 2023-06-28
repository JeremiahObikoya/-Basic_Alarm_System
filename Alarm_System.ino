const int trig = 7;
const int eco = 4;
const int buzzer = 9;
int microsec = 0;
int alarmV;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
}

long distance(){
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay (10);
  digitalWrite(trig, LOW);
  microsec = pulseIn(eco, HIGH);
  return microsec*0.017;
}
void loop() {
  // put your main code here, to run repeatedly:
  long dis = distance();
  Serial.print(dis);
  Serial.println("cm");
  if (dis < 50){
    alarmV = map (dis, 50, 0, 0, 255);
    analogWrite(buzzer, alarmV);
  } 
  else {
    analogWrite(buzzer, 0);
  }
}
