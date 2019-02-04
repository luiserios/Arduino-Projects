const int redLEDpin = 11;
const int blueLEDpin = 10;
const int greenLEDpin = 9;

const int redSensorpin = A0;
const int whiteSensorpin = A1;
const int blueSensorpin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int whiteSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorpin);
  delay(5);
  whiteSensorValue = analogRead(whiteSensorpin);
  delay(5);
  blueSensorValue = analogRead(blueSensorpin);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t White/Green: ");
  Serial.print(whiteSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue / 4;
  greenValue = whiteSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  analogWrite(redLEDpin, redValue);
  analogWrite(greenLEDpin, greenValue);
  analogWrite(blueLEDpin, blueValue);
}
