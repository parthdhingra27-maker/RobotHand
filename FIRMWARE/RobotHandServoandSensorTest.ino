#include <Wire.h>
#include <Servo.h>

// ----- ADS1115 Address -----
#define ADS_ADDR 0x48   // Default address

// ----- Servo Objects -----
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// ----- Pin Assignments -----
int servoPin1 = 13;
int servoPin2 = 12;
int servoPin3 = 14;
int servoPin4 = 27;

// ----- Basic Setup -----
void setup() {
  Serial.begin(115200);

  // I2C init
  Wire.begin(21, 22);   // SDA = 21, SCL = 22

  // Servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  Serial.println("Robot Hand Firmware Started");
}

// ----- Read From ADS1115 -----
int16_t readADS(int channel) {
  // Select channel
  uint16_t config = 0x8400; // Single-ended AIN0
  if(channel == 1) config = 0x9400; // AIN1
  if(channel == 2) config = 0xA400; // AIN2
  if(channel == 3) config = 0xB400; // AIN3

  // Always add fixed bits
  config |= 0x8000;  // Start single conversion
  config |= 0x0183;  // 4.096V range, 128SPS

  Wire.beginTransmission(ADS_ADDR);
  Wire.write(0x01);                   // Config register
  Wire.write(config >> 8);
  Wire.write(config & 0xFF);
  Wire.endTransmission();

  delay(8); // ADS1115 conversion time

  Wire.beginTransmission(ADS_ADDR);
  Wire.write(0x00);                   // Conversion register
  Wire.endTransmission();

  Wire.requestFrom(ADS_ADDR, 2);
  int16_t result = (Wire.read() << 8) | Wire.read();
  return result;
}

// ----- Map Flex → Servo -----
int mapFlexToAngle(int16_t v) {
  // You will tune these
  int minV = 12000;
  int maxV = 24000;

  v = constrain(v, minV, maxV);
  return map(v, minV, maxV, 0, 180);
}

// ----- MAIN LOOP -----
void loop() {
  int s1 = mapFlexToAngle(readADS(0));
  int s2 = mapFlexToAngle(readADS(1));
  int s3 = mapFlexToAngle(readADS(2));
  int s4 = mapFlexToAngle(readADS(3));

  servo1.write(s1);
  servo2.write(s2);
  servo3.write(s3);
  servo4.write(s4);

  // Debug output
  Serial.print("S1: "); Serial.print(s1);
  Serial.print("  S2: "); Serial.print(s2);
  Serial.print("  S3: "); Serial.print(s3);
  Serial.print("  S4: "); Serial.println(s4);

  delay(10);
}
