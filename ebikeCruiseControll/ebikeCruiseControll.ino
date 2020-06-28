int bikeSpeed = 0;
int throttleInput = 0;
int throttleOutput = 0;
int cruiseThrottle = 0;
int cruiseSpeed = 0;
int swich = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);  //  throttle input
  pinMode(9, OUTPUT); //  throttle output
  pinMode(6, INPUT);  //  bike speed
  pinMode(11, INPUT); //  swich for cruise on/off
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bikeSpeed = digitalRead(6);
  throttleInput = digitalRead(3);
  throttleOutput = digitalRead(9);
  swich = digitalRead(11);
  
  if (swich == HIGH){
    cruiseThrottle = throttleInput;
    cruiseSpeed = bikeSpeed;
    Serial.println(cruiseThrottle);
    
    while (swich == HIGH){
      if (bikeSpeed > cruiseSpeed) {
        digitalWrite(9, LOW);
        Serial.println("Bike speed high. Throttling down");
        delay(500);
        }
      if (bikeSpeed < cruiseSpeed){
        digitalWrite(9, HIGH);
        Serial.println("Bike speed low. Throttling up");
        delay(200);  
        }
      if (bikeSpeed == cruiseSpeed){
        delay(200);
        }
      Serial.println(bikeSpeed);
      Serial.println(throttleInput);
      //digitalWrite(9, cruiseThrottle); //possibly useless
      
      }
  }
  
  else{
  digitalWrite(9, throttleInput);
  Serial.println(throttleInput);
  }  




//void loop end
}
