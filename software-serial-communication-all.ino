#include <SoftwareSerial.h>

// Define RX and TX pins for SoftwareSerial
#define wemos_TX_PIN 0 //D3
#define wemos_RX_PIN 2 //D4

// Create a SoftwareSerial object
SoftwareSerial mySerial(wemos_TX_PIN, wemos_RX_PIN);

void setup() {
  // Start the hardware serial for debugging
  Serial.begin(9600);

  // Start the software serial port
  mySerial.begin(9600);
}

void loop() {
  // Check for data on the SoftwareSerial port and read it
  if (mySerial.available()) {
    String receivedData = readFromSerial();
    Serial.println("Received via SoftwareSerial: " + receivedData);
  }

  // Check for data on the Hardware Serial port and send it via SoftwareSerial
  if (Serial.available()) {
    String sendData = Serial.readStringUntil('\n');
    writeToSerial(sendData);
    Serial.println("Sent via SoftwareSerial: " + sendData);
  }
}

// Function to read data from SoftwareSerial
String readFromSerial() {
  String data = "";
  while (mySerial.available()) {
    char c = mySerial.read();
    data += c;
    delay(5); // Small delay to allow more data to arrive
  }
  return data;
}

// Function to write data to SoftwareSerial
void writeToSerial(String data) {
  mySerial.println(data);
}
