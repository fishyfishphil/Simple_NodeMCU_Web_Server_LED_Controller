#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "ekwilinjoumase.com";
const char* password = "tessie123";

ESP8266WebServer server(80);

String page = "";
int GreenLEDPin = 12;
int RedLEDPin = 13;
int BlueLEDPin = 14;
void setup(void){
  page = "<!doctype html><html lang=\"en\"><head><meta charset=\"utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\"><link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\" integrity=\"sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T\" crossorigin=\"anonymous\"><title>LED Controller</title></head><body><div class=\"card\"><div class=\"card-header\"> Simple NodeMCU Web Server</div><div class=\"card-body\"><h5 class=\"card-title\">LED Controller</h5><div class=\"btn-group\" role=\"group\" aria-label=\"Basic example\"> <a href=\"All\" class=\"btn btn-primary\">All</a> <a href=\"Red\" class=\"btn btn-primary\">Red</a> <a href=\"Blue\" class=\"btn btn-primary\">Blue</a> <a href=\"Green\" class=\"btn btn-primary\">Green</a> <a href=\"Purple\" class=\"btn btn-primary\">Purple</a> <a href=\"Cyan\" class=\"btn btn-primary\">Cyan</a><a href=\"Yellow\" class=\"btn btn-primary\">Yellow</a>  <a href=\"Off\" class=\"btn btn-primary\">Off</a></div></div></div></body></html>";
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
  digitalWrite(GreenLEDPin, LOW);
  digitalWrite(RedLEDPin, LOW);
  digitalWrite(BlueLEDPin, LOW);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/Red", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, HIGH);
    digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BlueLEDPin, LOW);
  });
  server.on("/Green", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, LOW);
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(BlueLEDPin, LOW);
  });
  server.on("/Blue", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, LOW);
    digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BlueLEDPin, HIGH);
  });
  server.on("/Yellow", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, HIGH);
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(BlueLEDPin, LOW);
  });
  server.on("/Purple", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, HIGH);
    digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BlueLEDPin, HIGH);
  });
  server.on("/Cyan", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, LOW);
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(BlueLEDPin, HIGH);
  });
  server.on("/All", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, HIGH);
    digitalWrite(GreenLEDPin, HIGH);
    digitalWrite(BlueLEDPin, HIGH);
  });
  server.on("/Off", [](){
    server.send(200, "text/html", page);
    digitalWrite(RedLEDPin, LOW);
    digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BlueLEDPin, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
