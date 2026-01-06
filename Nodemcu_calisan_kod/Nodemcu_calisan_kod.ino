
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <ESP32WiFi.h>

ESP8266WebServer server(80);
uint8_t PIN_00 = 0;
uint8_t PIN_01 = 1;
uint8_t PIN_02 = 2;
uint8_t PIN_03 = 3;
uint8_t PIN_04 = 4;
uint8_t PIN_05 = 5;
uint8_t PIN_06 = 7;
uint8_t PIN_07 = 0;
StaticJsonDocument<1024> jsonDocument;
char buffer[1024];

void handlePost() {
  if (server.hasArg("plain") == false)
   {
  }
  String body = server.arg("plain");
  deserializeJson(jsonDocument, body);
  

  int pin = jsonDocument["pin"];
  bool stat = jsonDocument["stat"];
   Serial.print(body);
   setStatIoPin(pin,stat);
  String resp= GetPinStatus();
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "application/json", resp);
}

void setStatIoPin(int pin,bool stat)
{
switch(pin)
{
  case 0:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_00,LOW);
    }
     else 
     {
     digitalWrite(PIN_00,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

   case 1:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_01,LOW);
    }
     else 
     {
     digitalWrite(PIN_01,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

   case 2:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_02,LOW);
    }
     else 
     {
     digitalWrite(PIN_02,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

   case 3:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_03,LOW);
    }
     else 
     {
     digitalWrite(PIN_03,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

     case 4:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_04,LOW);
    }
     else 
     {
     digitalWrite(PIN_04,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

      case 5:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_05,LOW);
    }
     else 
     {
     digitalWrite(PIN_05,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

       case 6:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_05,LOW);
    }
     else 
     {
     digitalWrite(PIN_05,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }

      case 7:
  {
   if(stat)
    {
      Serial.print(String(pin));
      Serial.print("Low");
      digitalWrite(PIN_05,LOW);
    }
     else 
     {
     digitalWrite(PIN_05,HIGH);
       Serial.print(String(pin));
        Serial.print("High");
     }
    break;
  }


}
}

void getValues()
{
  Serial.print("Start");
  String resp= GetPinStatus();
   Serial.println(WiFi.localIP());
 Serial.println(resp);
  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200, "application/json",resp);
}

void setupApi() {
  server.on("/getValues", getValues);
  server.on("/setStatus", HTTP_POST, handlePost);
  server.begin();
}
void setup() {
  Serial.begin(115200);
  delay(1500); 
  WiFi.begin("NODEMCU24","20962096");
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000);
    Serial.print('.');
  }
    Serial.println(WiFi.localIP());
    pinMode(PIN_00, OUTPUT);
    pinMode(PIN_01, OUTPUT);
    pinMode(PIN_02, OUTPUT);
    pinMode(PIN_03, OUTPUT);
    pinMode(PIN_04, OUTPUT);
    pinMode(PIN_05, OUTPUT);
    pinMode(PIN_06, OUTPUT);
    pinMode(PIN_07, OUTPUT);
    setupApi();
}

void loop() {
 server.handleClient();
}

String GetPinStatus()
{
    int status0 = digitalRead(PIN_00);
    int status1 = digitalRead(PIN_01);
    int status2 = digitalRead(PIN_02);
    int status3 = digitalRead(PIN_03);
    int status4 = digitalRead(PIN_04);
    int status5 = digitalRead(PIN_05);
    int status6 = digitalRead(PIN_06);
    int status7 = digitalRead(PIN_07);
  JsonArray array = jsonDocument.to<JsonArray>();
  JsonObject nested = array.createNestedObject();
  nested["Pin"] = 0;
  nested["Value"] =status0;

 JsonObject nested1 = array.createNestedObject();
  nested1["Pin"] = 1;
  nested1["Value"] =status1;

   JsonObject nested2 = array.createNestedObject();
  nested2["Pin"] = 2;
  nested2["Value"] =status2;

  JsonObject nested3 = array.createNestedObject();
  nested3["Pin"] = 3;
  nested3["Value"] =status3;

  JsonObject nested4 = array.createNestedObject();
  nested4["Pin"] = 4;
  nested4["Value"] =status4;

  JsonObject nested5 = array.createNestedObject();
  nested5["Pin"] = 5;
  nested5["Value"] =status5;

  JsonObject nested6 = array.createNestedObject();
  nested6["Pin"] = 6;
  nested6["Value"] =status6;

  JsonObject nested7 = array.createNestedObject();
  nested7["Pin"] = 7;
  nested7["Value"] =status7;

  String json_string;
  serializeJson(array,json_string);
  return json_string;
}