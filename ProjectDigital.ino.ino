#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <Portal.h>
#include <SerialTransceiver.h>
#include <Transcriber.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>
#include <FirebaseArduino.h>

const char* ssid     = "noswifi";
const char* password = "789456123";
const int pinOutput = D0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinOutput, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin("projectdigital-3df20.firebaseio.com", "CwYa5ZEOGK4JR40B8KqejehHWwkMMBP1woCmDhXM");
  digitalWrite(pinOutput, HIGH);


  Serial.println("Connect Firebase Successful");

}

void loop() {

  if (Firebase.getBool("setting/forMCU"))
  {
    digitalWrite(pinOutput, LOW);
    Serial.println("Relay Close");
    Serial.println(Firebase.getBool("setting/forMCU"));
  } else
  {
    digitalWrite(pinOutput, HIGH);
    Serial.println("Relay Open");
    Serial.println(Firebase.getBool("setting/forMCU"));
  }


  // put your main code here, to run repeatedly:

}
