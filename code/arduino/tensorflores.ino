// INCLUDE THE MODEL
#include "model.h"

// DEFINE THE MODEL INSTANCE
Conect2AI::TensorFlores::MultilayerPerceptron modelo;

// DEFINE SENSOR PINS
int sensorPin0 = A0; // 2^10 = 1024 -> range: 0 to 1023
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;

// INITIALIZE SENSOR VALUES
float sensor0Value = -1; 
float sensor1Value = -1; 
float sensor2Value = -1; 
float sensor3Value = -1; 

// INPUT AND OUTPUT BUFFERS
float input[4] = {-1.0, -1.0, -1.0, -1.0};
float output = -1.0;

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // READ SENSOR VALUES AND NORMALIZE TO [0, 1]
  sensor0Value = analogRead(sensorPin0)/1023.0;
  sensor1Value = analogRead(sensorPin1)/1023.0;
  sensor2Value = analogRead(sensorPin2)/1023.0;
  sensor3Value = analogRead(sensorPin3)/1023.0;

  // PASS SENSOR VALUES AS MODEL INPUT
  float input[4] = {sensor0Value, sensor1Value, sensor2Value, sensor3Value};

  // RUN MODEL PREDICTION
  float output = modelo.predict(input);

  // PRINT SENSOR VALUES AND MODEL OUTPUT
  Serial.print("sensor0Value = ");
  Serial.println(sensor0Value);
  Serial.print("sensor1Value = ");
  Serial.println(sensor1Value);
  Serial.print("sensor2Value = ");
  Serial.println(sensor2Value);
  Serial.print("sensor3Value = ");
  Serial.println(sensor3Value);
  Serial.println(" - - - - - - - - - ");
  Serial.print("OUTPUT = ");
  Serial.println(output, 7);
  Serial.println(" - - - - - - - - - ");

  delay(2000); // Delay in milliseconds
}
