int trigger = 13;
int echo = 12;
int lock=9;
int unlock=8;
int light=3;
int fan=2;
float duration;
int distance;
int state;
int sensorInput;
double temp;



void setup() {
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(lock, OUTPUT);
pinMode(unlock, OUTPUT);
pinMode(light, OUTPUT);
pinMode(fan, OUTPUT);
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
    heat();
  }
  else{
    digitalWrite(lock, HIGH);
    digitalWrite(unlock, LOW);
    digitalWrite(light, LOW);
    digitalWrite(fan, LOW);
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

void heat(){
sensorInput = analogRead(A2); //read the analog sensor and store it
temp = (double)sensorInput / 1024; //find percentage of input reading
temp = temp * 5; //multiply by 5V to get voltage
//temp = temp – 0.5; //Subtract the offset
temp = temp * 100; //Convert to degrees
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
      if (temp>70){
    digitalWrite(fan, HIGH);
  }
  else{
    digitalWrite(fan, LOW);
  }
}
