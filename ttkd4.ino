#include "pindefs.h"
#include "leds.h"
#include "button.h"
#include <PubSubClient.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "****";
const char *password = "****";
WebServer webserver(80);

void wifiSetup()
{

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void webServerSetup()
{
  webserver.on("/", handleRoot);
  webserver.onNotFound(handleRoot);
  webserver.on("/buttonPress", webPress);
  webserver.begin();
}

void setup()
{
  Serial.begin(115200);
  ledSetup();
  buttonSetup();
  wifiSetup();
  webServerSetup();
}

void loop()
{
  buttonRun();
  showRandom();
  webserver.handleClient();
}

void handleRoot()
{
  String temp PROGMEM = "<!DOCTYPE html><html><head> <meta http-equiv='refresh' content='10'/><title>TTKIOT Demo</title></head><body> <body> <h1>Hello from TTKIOT!</h1><button onclick='myFunction()'>VIRTUAL BUTTON</button> <p id='demo'></p></body> <script>function myFunction(){let request=new XMLHttpRequest(); request.open('GET', '/buttonPress'); request.send(); request.onload=()=>{if (request.status==200){document.getElementById('demo').innerHTML=request.response;}}}</script></body></html>";
  webserver.send(200, "text/html", temp);
}

void webPress(){
   buttonPress();
   webserver.send(200, "text/plain", "<h3>Button pressed</h3>");
}