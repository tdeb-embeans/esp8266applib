/*
 * ESP8266 Arduino Application Library
 * Copyright (C) 2016  TANMOY DEB (tanmoy.deb@incise.in)
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "esp8266app.h"

ESP8266APP::ESP8266APP()
{

}

ESP8266APP::ESP8266APP(int p_pin)
{
    pinMode(p_pin, OUTPUT);
    _pin = p_pin;

}

void ESP8266APP::handlesw1on() {
  server.send(200, "text/plain", "1 ON");
  digitalWrite(_pin, HIGH);
}

void ESP8266APP::handlesw1off() {
  server.send(200, "text/plain", "1 OFF");
  digitalWrite(_pin, LOW);
}

void ESP8266APP::handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void ESP8266APP::connectWiFi(char* _ssid, char* _password){
    WiFi.begin(ssid, password);
}

//use this during setup, then call other functions
//otherwise it will throw NULL pointer exception,
//this cases will be handled later
void ESP8266APP::setupWebServer(int p_port){
    _port = p_port;
    ESP8266WebServer server(p_port);
}

void ESP8266APP::log(char* str){
    Serial.println(str);
}



