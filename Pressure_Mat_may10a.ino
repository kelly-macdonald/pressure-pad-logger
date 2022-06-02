/*
  This code takes input from 6 force sensitive resistors which are installed in 2 pressure mats. The output is to update two variables,
  person_on1 and person_on2 to the Arduion IoT Cloud. These are boolean variables which represent whether there is a person
  standing on the mat (TRUE) or is not (FALSE). The code has been used successfully on an Arduino MKR WiFi 1010.

  Sketch generated by the Arduino IoT Cloud Thing "Pressure Mat"
  https://create.arduino.cc/cloud/things/7bf82251-4657-4332-8773-6034https://create.arduino.cc/editor/kellymacdonald/ff674d08-d16a-4c99-935e-694426d521dfc8054202

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool person_on1;
  bool person_on2;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#define FORCE_SENSOR_PIN0 A0 // the FSR and 10K pulldown are connected to A0
#define FORCE_SENSOR_PIN1 A1 // the FSR and 10K pulldown are connected to A1
#define FORCE_SENSOR_PIN2 A2 // the FSR and 10K pulldown are connected to A2

#define FORCE_SENSOR_PIN3 A3 // the FSR and 10K pulldown are connected to A3
#define FORCE_SENSOR_PIN4 A4 // the FSR and 10K pulldown are connected to A4
#define FORCE_SENSOR_PIN5 A5 // the FSR and 10K pulldown are connected to A5

#define WIFI_CONNECTIVITY_STATUS_PIN 13 // the positive end of an LED is connected to 13

const int threshold = 800; //Arbitary unit force threshold, adjust as needed

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(4);
  pinMode(WIFI_CONNECTIVITY_STATUS_PIN, OUTPUT);    // Sets the wifi connectivity pin as output
  
}

void loop() {
  
  // Read pressure at each of the 6 sensors
  int pressure0 = analogRead(FORCE_SENSOR_PIN0); 
  int pressure1 = analogRead(FORCE_SENSOR_PIN1);
  int pressure2 = analogRead(FORCE_SENSOR_PIN2);
  int pressure3 = analogRead(FORCE_SENSOR_PIN3);
  int pressure4 = analogRead(FORCE_SENSOR_PIN4);
  int pressure5 = analogRead(FORCE_SENSOR_PIN5);
  
  // Determine if any of the first three sensors are under pressure
  if(pressure0 > threshold || pressure1 > threshold || pressure2 > threshold){
    person_on1 = true;
  }
  else{
    person_on1 = false;
  }
  
  // Determine if any of the second three sensors are under pressure
  if(pressure3 > threshold || pressure4 > threshold || pressure5 > threshold){
    person_on2 = true;
  }
  else{
    person_on2 = false;
  }
  
  // Update boolean variables over the cloud
  ArduinoCloud.update();
  
  // Print debug info to serial monitor
  ArduinoCloud.printDebugInfo();
  
  // Turn LED on or off based on connection to internet
  if (ArduinoCloud.connected()){
    digitalWrite(WIFI_CONNECTIVITY_STATUS_PIN, HIGH); // sets the digital pin 13 on
  }
  else{
    digitalWrite(WIFI_CONNECTIVITY_STATUS_PIN, LOW);  // sets the digital pin 13 off
  }
  
  // Print pressure values to serial monitor (for calibrating and debugging)
  Serial.print("pressure0 = ");
  Serial.println(pressure0);
  Serial.print("pressure1 = ");
  Serial.println(pressure1);
  Serial.print("pressure2 = ");
  Serial.println(pressure2);
  Serial.print("pressure3 = ");
  Serial.println(pressure3);
  Serial.print("pressure4 = ");
  Serial.println(pressure4);
  Serial.print("pressure5 = ");
  Serial.println(pressure5);
}



/*
  Since PersonOn1 is READ_WRITE variable, onPersonOn1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onPersonOn1Change()  {
  // Add your code here to act upon PersonOn1 change
}

/*
  Since PersonOn2 is READ_WRITE variable, onPersonOn2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onPersonOn2Change()  {
  // Add your code here to act upon PersonOn2 change
}
