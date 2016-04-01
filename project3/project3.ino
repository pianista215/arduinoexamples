const int sensorPin = A0;
const float baseLineTemp = 26.5;


void setup() {
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber < 5 ; pinNumber++){
     pinMode(pinNumber, OUTPUT);
     digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  //Convert the adc reading to volgate
  float voltage = (sensorVal/1024.0) *5.0;
  Serial.print(", Volts:");
  Serial.print(voltage);
  
  //Temperature (converting voltage into temperature)
  Serial.print(", degrees C");
  float temperature = (voltage - .5)*100;
  Serial.println(temperature);
  
  if(temperature < baseLineTemp){
     digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
  } else if(temperature >= baseLineTemp +2 && temperature < baseLineTemp + 4){
     digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
  } else if(temperature >= baseLineTemp +4 && temperature < baseLineTemp + 6){
     digitalWrite(2, HIGH);
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
  } else if(temperature >= baseLineTemp +6){
     digitalWrite(2, HIGH);
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
  }
  delay(250);

}
