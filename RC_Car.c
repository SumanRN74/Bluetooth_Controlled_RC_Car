/*
 * Project Name: Bluetooth-Controlled RC Car
 * Designed For: Arduino Uno + L298N Motor Driver
 */

#include <SoftwareSerial.h>

SoftwareSerial HC05(9, 10); // RX, TX

// === Pin Definitions ===
#define led1 13   // Status LED

#define enA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 11
#define enB 12

char command;

void setup() {
  // LED setup
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);  // LED ON when powered

  // Bluetooth setup
  HC05.begin(9600);

  // Motor driver setup
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize with motors stopped
  Stop();
}

void loop() {
  if (HC05.available() > 0) {
    command = HC05.read();

    Stop(); // Default stop before executing command

    switch (command) {
      case 'F': Forward(); break;
      case 'B': Back(); break;
      case 'L': Left(); break;
      case 'R': Right(); break;
      case 'G': ForwardLeft(); break;
      case 'I': ForwardRight(); break;
      case 'H': BackLeft(); break;
      case 'J': BackRight(); break;
      case 'S': Stop(); break;
    }
  }
}

// === Movement Functions ===
void Forward() {
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void Back() {
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void Left() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void Right() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void ForwardLeft() {
  analogWrite(enA, 100);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void ForwardRight() {
  analogWrite(enA, 200);
  analogWrite(enB, 100);
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void BackLeft() {
  analogWrite(enA, 100);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void BackRight() {
  analogWrite(enA, 200);
  analogWrite(enB, 100);
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void Stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}
