int trigger = 13;
int echo = 12;
int lock=9;
int unlock=8;
int light=3;
float duration;
int distance;
int state;




void setup() {
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(lock, OUTPUT);
pinMode(unlock, OUTPUT);
pinMode(light, OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  sonic();
  delay(1000);  
}

void sonic(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance <100){
    digitalWrite(unlock, HIGH);
    digitalWrite(lock, LOW);
    lamp(); 
  }
  else{
    digitalWrite(lock, HIGH);
    digitalWrite(unlock, LOW);
    digitalWrite(light, LOW); 
  }
}

void lamp(){
  int state = analogRead(A1);
  Serial.print("Darkness: ");
  Serial.println(state);
        if (state >300){
    digitalWrite(light, HIGH);
  }
  else{
    digitalWrite(light, LOW);
  }
  
}
