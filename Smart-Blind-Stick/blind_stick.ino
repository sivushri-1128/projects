// Smart Blind Stick - 3 Direction Sensing

// LEFT SENSOR
#define trigL 2
#define echoL 3

// FRONT SENSOR
#define trigF 4
#define echoF 5

// RIGHT SENSOR
#define trigR 6
#define echoR 7

// BUZZER
#define buzzer 8

long duration;
int distL, distF, distR;

// Function to measure distance
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);

  pinMode(trigF, OUTPUT);
  pinMode(echoF, INPUT);

  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Read all sensors
  distL = getDistance(trigL, echoL);
  distF = getDistance(trigF, echoF);
  distR = getDistance(trigR, echoR);

  Serial.print("L: "); Serial.print(distL);
  Serial.print("  F: "); Serial.print(distF);
  Serial.print("  R: "); Serial.println(distR);

  // 🚨 PRIORITY: FRONT > LEFT > RIGHT

  if (distF > 0 && distF <= 50) {
    // FRONT → VERY FAST BEEP
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(50);
  }
  else if (distL > 0 && distL <= 50) {
    // LEFT → MEDIUM SPEED BEEP
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
  }
  else if (distR > 0 && distR <= 50) {
    // RIGHT → SLOW BEEP
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
  else {
    // NO OBSTACLE
    digitalWrite(buzzer, LOW);
  }

  delay(50);
}
