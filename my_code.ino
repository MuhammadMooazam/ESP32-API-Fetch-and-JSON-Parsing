#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "time.h"

String serverName = "http://137.184.54.1:5000/api/data/123";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 5 * 3600;
const int   daylightOffset_sec = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin("Dreamnet (( Mooazam ))", "Arham123");
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer, "time.nist.gov");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    //    HttpClient http;
    WiFiClient client;
    String serverPath = serverName;
    Serial.println(serverPath);
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
      Serial.println("Failed to obtain time");
      return;
    }
    Serial.print("Hour: ");
    Serial.println(&timeinfo, "%H");
    //  Serial.print("Hour (12 hour format): ");
    //  Serial.println(&timeinfo, "%I");
    Serial.print("Minute: ");
    Serial.println(&timeinfo, "%M");
    Serial.print("Second: ");
    Serial.println(&timeinfo, "%S");
    Serial.print("Date: ");
    Serial.println(&timeinfo, "%d");
    Serial.print("Month: ");
    Serial.println(&timeinfo, "%B");
    Serial.print("Year: ");
    Serial.println(&timeinfo, "%Y");
    Serial.println();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      String input = payload;

      StaticJsonDocument<1024> doc;

      DeserializationError error = deserializeJson(doc, input);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
      }

      int initialPostion_Xpos = doc["initialPostion"]["Xpos"]; // 0
      int initialPostion_Ypos = doc["initialPostion"]["Ypos"]; // 0

      Serial.println(initialPostion_Xpos);
      Serial.println(initialPostion_Ypos);

      JsonArray pos_X_cord = doc["pos"]["X_cord"];
      int pos_X_cord_0 = pos_X_cord[0]; // 0
      int pos_X_cord_1 = pos_X_cord[1]; // 15
      int pos_X_cord_2 = pos_X_cord[2]; // 30
      int pos_X_cord_3 = pos_X_cord[3]; // 45
      int pos_X_cord_4 = pos_X_cord[4]; // 60
      int pos_X_cord_5 = pos_X_cord[5]; // 75
      int pos_X_cord_6 = pos_X_cord[6]; // 90
      int pos_X_cord_7 = pos_X_cord[7]; // 105
      int pos_X_cord_8 = pos_X_cord[8]; // 120
      int pos_X_cord_9 = pos_X_cord[9]; // 135
      int pos_X_cord_10 = pos_X_cord[10]; // 150
      int pos_X_cord_11 = pos_X_cord[11]; // 165
      int pos_X_cord_12 = pos_X_cord[12]; // 180

      Serial.println(pos_X_cord_0);
      Serial.println(pos_X_cord_1);
      Serial.println(pos_X_cord_2);
      Serial.println(pos_X_cord_3);
      Serial.println(pos_X_cord_4);
      Serial.println(pos_X_cord_5);
      Serial.println(pos_X_cord_6);
      Serial.println(pos_X_cord_7);
      Serial.println(pos_X_cord_8);
      Serial.println(pos_X_cord_9);
      Serial.println(pos_X_cord_10);
      Serial.println(pos_X_cord_11);
      Serial.println(pos_X_cord_12);


      JsonArray pos_Y_cord = doc["pos"]["Y_cord"];
      int pos_Y_cord_0 = pos_Y_cord[0]; // 0
      int pos_Y_cord_1 = pos_Y_cord[1]; // 15
      int pos_Y_cord_2 = pos_Y_cord[2]; // 30
      int pos_Y_cord_3 = pos_Y_cord[3]; // 45
      int pos_Y_cord_4 = pos_Y_cord[4]; // 60
      int pos_Y_cord_5 = pos_Y_cord[5]; // 75
      int pos_Y_cord_6 = pos_Y_cord[6]; // 90
      int pos_Y_cord_7 = pos_Y_cord[7]; // 105
      int pos_Y_cord_8 = pos_Y_cord[8]; // 120
      int pos_Y_cord_9 = pos_Y_cord[9]; // 135
      int pos_Y_cord_10 = pos_Y_cord[10]; // 150
      int pos_Y_cord_11 = pos_Y_cord[11]; // 165
      int pos_Y_cord_12 = pos_Y_cord[12]; // 180

      Serial.println(pos_Y_cord_0);
      Serial.println(pos_Y_cord_1);
      Serial.println(pos_Y_cord_2);
      Serial.println(pos_Y_cord_3);
      Serial.println(pos_Y_cord_4);
      Serial.println(pos_Y_cord_5);
      Serial.println(pos_Y_cord_6);
      Serial.println(pos_Y_cord_7);
      Serial.println(pos_Y_cord_8);
      Serial.println(pos_Y_cord_9);
      Serial.println(pos_Y_cord_10);
      Serial.println(pos_Y_cord_11);
      Serial.println(pos_Y_cord_12);

      const char* Device = doc["Device"]; // "123"
      const char* id_ = doc["_id"]; // "61c0bfc546416f0095788fb6"

      Serial.println(Device);
      Serial.println(id_);

      JsonObject customer = doc["customer"];
      const char* customer_id = customer["_id"]; // "61c0bfc546416f0095788fb1"
      const char* customer_email = customer["email"]; // "ammartanweer7370@gmail.com"
      const char* customer_password = customer["password"]; // "Muhammad Ammar 1"
      int customer_v = customer["__v"]; // 0

      int v = doc["__v"]; // 0

      Serial.println(customer_id);
      Serial.println(customer_email);
      Serial.println(customer_password);
      Serial.println(customer_v);
      Serial.println(v);

    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}
