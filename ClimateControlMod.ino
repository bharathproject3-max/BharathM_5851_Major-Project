// Pin Definitions
const int TEMP_PIN = A0;    
const int MOTOR_PIN = 9;    

const float MIN_TEMP = 27.0;
const float MAX_TEMP = 40.0;
const int MIN_PWM = 0;
const int MAX_PWM = 255;

unsigned long previousMillis = 0;
const long printInterval = 500; // 500 ms 

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, MIN_PWM); 
}

void loop() {
  unsigned long currentMillis = millis();
  float currentTemp = readTemperature(TEMP_PIN);
  int currentPWM = calculatePWM(currentTemp);
  analogWrite(MOTOR_PIN, currentPWM);
  if (currentMillis - previousMillis >= printInterval) {
    previousMillis = currentMillis;
    
    Serial.print("Temp: ");
    Serial.print(currentTemp, 1); 
    Serial.print("C, PWM: ");
    Serial.println(currentPWM);
  }
}

float readTemperature(int pin) {
  int rawValue = analogRead(pin);
  float voltage = (rawValue / 1024.0) * 5.0; 
  return voltage * 100.0; 
}

int calculatePWM(float temp) {
  if (temp < MIN_TEMP) {
    return MIN_PWM; 
  } else if (temp >= MAX_TEMP) {
    return MAX_PWM; 
  } else {
    float ratio = (temp - MIN_TEMP) / (MAX_TEMP - MIN_TEMP);
    return (int)(ratio * MAX_PWM);
  }
}