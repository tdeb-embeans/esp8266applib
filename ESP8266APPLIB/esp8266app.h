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

#ifndef ESP8266APP_H
#define ESP8266APP_H

#include "Arduino.h"

class ESP8266APP
{
public:
    ESP8266APP();
    ESP8266APP(int);
    void handlesw1on();
    void handlesw1off();
    void handleNotFound();
    void connectWiFi(char* _ssid, char* _password);
    void setupWebServer(int p_port);
    void log(char*);
private:
    ESP8266WebServer server;
    char* _ssid;
    char* _password;
    int _pin;
    int _port;
};

#endif // ESP8266APP_H
