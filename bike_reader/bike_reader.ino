int const MG_READER = A1;
boolean isContact = false;
unsigned long lastReadTime;
int const TYRE_CIRC = 213; //in cm

void setup() {
  pinMode(MG_READER, INPUT); // Sets the trigPin as an Output 
  lastReadTime = millis();
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
  
  int val = analogRead(MG_READER);
//  delay(300);
//
//  Serial.println(val);

  if(val>0){ 
    if(!isContact){
      isContact = true;
      unsigned long now = millis();
      unsigned long elapsedTime = now - lastReadTime;
      lastReadTime = now; 
      float sp_kph = TYRE_CIRC *36 / elapsedTime ; 
//      Serial.println(elapsedTime); 
      String strSpeed = String(sp_kph);
      if(sp_kph < 10){
        strSpeed = "0" + strSpeed;
      }
 
      Serial.println("{speed: " + strSpeed + "}"); 
    }
  } else {
    isContact = false;  
  }
  

  
}
