#include<Wire.h> //Include Wire library for I2C
#include<LiquidCrystal_I2C.h> //Include LCD library for I2C

#define TRIG_PIN 6 //Define Trig pin for Ultrasonic Sensor
#define ECHO_PIN 5 //Define Echo pin for Ultrasonic Sensor

LiquidCrystal_I2C lcd(0x3F,16,2); //Set the LCD I2C address (0x3F) and dimensions (16x2)

void setup() {
  pinMode(TRIG_PIN,OUTPUT); //Set Trig pin as output
  pinMode(ECHO_PIN,INPUT); //Set Echo pin as input
  lcd.begin(); //Initialize the LCD
  lcd.backlight(); //Turn on the LCD backlight
}

void loop() {
  long duration; //Variable to store the duration of pulse
  int distanceCm,distanceInch; //Variables to store distance in cm and inches

  digitalWrite(TRIG_PIN,LOW); //Clear the Trig pin  
  delayMicroseconds(2); //Wait for 2 microseconds
  digitalWrite(TRIG_PIN,HIGH); //Set the Trig pin high
  delayMicroseconds(10); //Wait for 10 microseconds
  digitalWrite(TRIG_PIN,LOW); //Set the Trig pin low

  duration=pulseIn(ECHO_PIN,HIGH); //Read the Echo pin and return the sound wave travel time in microseconds
  distanceCm=duration*0.034/2; //Calculate the distance in cm
  distanceInch=duration*0.0133/2; //Calculate the distance in inches

  //Cap the maximum distance to 200 cm
  if(distanceCm>=100){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Maximum Distance");
    lcd.noBacklight();
  }else{
    lcd.backlight();
    lcd.clear(); //Clear the LCD display

    lcd.setCursor(0,0); //Set the cursor to column 0, row 0
    lcd.print("Distance: "); //Print "Distance:" on the LCD
    lcd.print(distanceCm); //Print the distance in cm
    lcd.print(" cm"); //Print "cm"
  
    lcd.setCursor(0,1); //Set the cursor to column 0, row 1
    lcd.print("Distance: "); //Print "Distance:" on the LCD
    lcd.print(distanceInch); //Print the distance in inches
    lcd.print(" inch"); //Print "inch"
  }
  delay(500); //Wait for 500 milliseconds before measuring again
}
