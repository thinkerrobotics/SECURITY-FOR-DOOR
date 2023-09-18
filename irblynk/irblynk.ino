
//Blynk Alert system
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "efTDWvYh_8BmsXYY7yngMFwbVMHStw8c"; //Auth code sent via Email
char ssid[] = "RDC A3"; //Wifi name
char pass[] = "rdgeiot";  //Wifi Password
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println(" Someone in the House");
    Blynk.notify("Alert : Someone in the House");
    flag=1;
  }
  else if (isButtonPressed==0)
  { 
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass); 
pinMode(D1,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnThings); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
