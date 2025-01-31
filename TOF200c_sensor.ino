/*
ESP module: ESP-WROOM-32
Getest met: Arduino IDE
Sensor: TOF-200C  VL53L0X ;
Doel: laser afstandmeting ;
Specs: I2C, 3V3 ;
Aansluiten (van sensor naar ESP)
VCC naar 3.3V
GND naar GND
SDA naar GPIO 21
SCL naar GPIO 22
*/

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (!lox.begin()) {
        Serial.println("Failed to initialize VL53L0X! Check connections.");
        while (1);
    }
    Serial.println("VL53L0X Initialized.");
}

void loop() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) { // Status 4 means no object detected
        Serial.print("Distance: ");
        Serial.print(measure.RangeMilliMeter);
        Serial.println(" mm");
    } else {
        Serial.println("Out of range.");
    }

    delay(1000); //delay between measurements
}
