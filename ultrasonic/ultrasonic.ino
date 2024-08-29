const int trigPin = 12; // Trigger pin of ultrasonic sensor
const int echoPin = 11; // Echo pin of ultrasonic sensor

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT); // Set echo pin as input
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);  // Set trigger pin low for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Set trigger pin high for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Set trigger pin low

  duration = pulseIn(echoPin, HIGH); // Read the duration of the echo pulse
  distance = duration * 0.0343 / 2; // Calculate distance in centimeters

  if (distance > 150) { // Check for maximum distance
    Serial.print("Maximux distance!!");
    Serial.print("\n");
//    distance = 150;
  }else if(distance <= 4){
    Serial.print("Minimum disatnce measured!!");
    Serial.print("\n");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(250); // Delay for 50 milliseconds
}
