
/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

#define NETWORK_LED 2      // led "NETWORK" on pcb
#define i2c_address 0x27   // i2c slave address for chip expander

#ifndef APSSID
#define APSSID "16CH_relay_AP"     // WiFi Access Point name
#define APPSK  ""                  // password
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

unsigned int i2c_register;
unsigned char variable_LOW, variable_HIGH;

unsigned char relay_1_state = 0;
unsigned char relay_2_state = 0;
unsigned char relay_3_state = 0;
unsigned char relay_4_state = 0;
unsigned char relay_5_state = 0;
unsigned char relay_6_state = 0;
unsigned char relay_7_state = 0;
unsigned char relay_8_state = 0;
unsigned char relay_9_state = 0;
unsigned char relay_10_state = 0;
unsigned char relay_11_state = 0;
unsigned char relay_12_state = 0;
unsigned char relay_13_state = 0;
unsigned char relay_14_state = 0;
unsigned char relay_15_state = 0;
unsigned char relay_16_state = 0;

unsigned char NewEvent;

ESP8266WebServer server(80);

void setup() {
  delay(500);

  pinMode(NETWORK_LED, OUTPUT);  
  digitalWrite(NETWORK_LED, LOW);
  
  Wire.begin();
  Serial.begin(115200);

  Wire.beginTransmission(i2c_address);
  Wire.write(0x00);            // A register
  Wire.write(0x00);            // set all of port A to outputs
  Wire.endTransmission();

  Wire.beginTransmission(i2c_address);
  Wire.write(0x01);            // B register
  Wire.write(0x00);            // set all of port B to outputs
  Wire.endTransmission();      

  
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("HTTP server started");

  server.on("/",      []() { server.send(200, "text/html", webPage()); });
  
  server.on("/1_on",  []() { relay_1_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/1_off", []() { relay_1_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/2_on",  []() { relay_2_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/2_off", []() { relay_2_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/3_on",  []() { relay_3_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/3_off", []() { relay_3_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/4_on",  []() { relay_4_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/4_off", []() { relay_4_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/5_on",  []() { relay_5_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/5_off", []() { relay_5_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/6_on",  []() { relay_6_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/6_off", []() { relay_6_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/7_on",  []() { relay_7_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/7_off", []() { relay_7_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/8_on",  []() { relay_8_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/8_off", []() { relay_8_state = 0;
                             server.send(200, "text/html", webPage()); });

  server.on("/9_on",  []() { relay_9_state = 1;
                             server.send(200, "text/html", webPage()); });
  
  server.on("/9_off", []() { relay_9_state = 0;
                             server.send(200, "text/html", webPage()); });  

  server.on("/10_on",  []() { relay_10_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/10_off", []() { relay_10_state = 0;
                              server.send(200, "text/html", webPage()); }); 

  server.on("/11_on",  []() { relay_11_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/11_off", []() { relay_11_state = 0;
                              server.send(200, "text/html", webPage()); });      
                                                                                                     
  server.on("/12_on",  []() { relay_12_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/12_off", []() { relay_12_state = 0;
                              server.send(200, "text/html", webPage()); });
                             
  server.on("/13_on",  []() { relay_13_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/13_off", []() { relay_13_state = 0;
                              server.send(200, "text/html", webPage()); });

  server.on("/14_on",  []() { relay_14_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/14_off", []() { relay_14_state = 0;
                              server.send(200, "text/html", webPage()); });

  server.on("/15_on",  []() { relay_15_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/15_off", []() { relay_15_state = 0;
                              server.send(200, "text/html", webPage()); });   

  server.on("/16_on",  []() { relay_16_state = 1;
                              server.send(200, "text/html", webPage()); });
  
  server.on("/16_off", []() { relay_16_state = 0;
                              server.send(200, "text/html", webPage()); });                                                   
                             
                                                                                                                                                                       

  server.on("/all_on", []() { relay_1_state = 1;
                              relay_2_state = 1;
                              relay_3_state = 1;
                              relay_4_state = 1;
                              relay_5_state = 1;
                              relay_6_state = 1;
                              relay_7_state = 1;
                              relay_8_state = 1;
                              relay_9_state = 1;
                              relay_10_state = 1;
                              relay_11_state = 1;
                              relay_12_state = 1;
                              relay_13_state = 1;
                              relay_14_state = 1;
                              relay_15_state = 1;
                              relay_16_state = 1;
                              server.send(200, "text/html", webPage()); });        

  server.on("/all_off", []() { relay_1_state = 0;
                               relay_2_state = 0;
                               relay_3_state = 0;
                               relay_4_state = 0;
                               relay_5_state = 0;
                               relay_6_state = 0;
                               relay_7_state = 0;
                               relay_8_state = 0;
                               relay_9_state = 0;
                               relay_10_state = 0;
                               relay_11_state = 0;
                               relay_12_state = 0;
                               relay_13_state = 0;
                               relay_14_state = 0;
                               relay_15_state = 0;
                               relay_16_state = 0;
                               server.send(200, "text/html", webPage()); });                               
}

void loop() {
  server.handleClient();

  if (WL_CONNECTED) { digitalWrite(NETWORK_LED, HIGH); }          // turn ON "NETWORK" led on pcb, when connection is ok
   else digitalWrite(NETWORK_LED, LOW);

  if(NewEvent){                                                   // if received new data, format it and send to i2c register

  i2c_register &= 0b0111111111111111; i2c_register |= relay_8_state<<15;
  i2c_register &= 0b1011111111111111; i2c_register |= relay_7_state<<14;
  i2c_register &= 0b1101111111111111; i2c_register |= relay_6_state<<13;
  i2c_register &= 0b1110111111111111; i2c_register |= relay_5_state<<12;
  i2c_register &= 0b1111011111111111; i2c_register |= relay_4_state<<11;
  i2c_register &= 0b1111101111111111; i2c_register |= relay_3_state<<10;
  i2c_register &= 0b1111110111111111; i2c_register |= relay_2_state<<9;
  i2c_register &= 0b1111111011111111; i2c_register |= relay_1_state<<8;
  
  i2c_register &= 0b1111111101111111; i2c_register |= relay_16_state<<7;
  i2c_register &= 0b1111111110111111; i2c_register |= relay_15_state<<6;
  i2c_register &= 0b1111111111011111; i2c_register |= relay_14_state<<5;
  i2c_register &= 0b1111111111101111; i2c_register |= relay_13_state<<4;
  i2c_register &= 0b1111111111110111; i2c_register |= relay_12_state<<3;
  i2c_register &= 0b1111111111111011; i2c_register |= relay_11_state<<2;
  i2c_register &= 0b1111111111111101; i2c_register |= relay_10_state<<1;
  i2c_register &= 0b1111111111111110; i2c_register |= relay_9_state;
    
  variable_LOW = lowByte(i2c_register);
  variable_HIGH = highByte(i2c_register);

  Wire.beginTransmission(i2c_address);
  Wire.write(0x12);                     // address bank A
  Wire.write(variable_LOW);
  Wire.endTransmission();
     
  Wire.beginTransmission(i2c_address);
  Wire.write(0x13);                     // address bank B
  Wire.write(variable_HIGH);
  Wire.endTransmission();

  NewEvent = 0;
     
  } 
}

String webPage()
{
  String web; 
  
  web += "<!DOCTYPE html><html>";
  web += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><title>SMART WIFI RELAY</title>";
  web += "<link href=\"data:image/png;base64,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\" rel=\"icon\" type=\"image/x-icon\" />";
  web += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
  web += "td {padding: 5px; height: 60px;}";
  web += "table.TOP_HEAD { width: 480px; height: 70px; background-color: #00c5fc; border-radius: 10px; font-size: 30px; font-weight: bold; box-shadow: 0px 0px 5px 1px grey; }";
  web += "table.SPACER { width: 480px; height: 5px; background-color: white; }";
  web += ".buttonON { width: 230px; height: 50px; align: center; border-radius: 10px; border: 0px solid black; background-color: #00c5fc; font-size: 20px; font-weight: bold; box-shadow: 0px 0px 5px 1px grey; }";
  web += ".buttonOFF { width: 230px; height: 50px; align: center; border-radius: 10px; border: 0px solid black; background-color: lightgrey; font-size: 20px; font-weight: bold; box-shadow: 0px 0px 5px 1px grey; }";
  web += ".buttonBOTTOM { width: 150px; height: 50px; align: center; border-radius: 10px; background-color: grey; background-position: center; background-repeat: no-repeat; border: 0px solid black; font-size: 20px; font-weight: bold; box-shadow: 0px 0px 5px 1px grey; }";
  
  web += "</style></head>";

  web += "<table class=\"TOP_HEAD\" align=\"center\"> <tbody> <tr><td align=\"center\">16 CHANNEL WIFI RELAY</td></tr> </tbody> </table>";
  web += "<p></p>";
  web += "<table class=\"SPACER\" align=\"center\"><tbody> <tr></tr> </tbody> </table>";
  web += "<p></p>";
  
  web += "<table width=\"500px\" align=\"center\"> <tbody>";
  web += "<tr>";
                 if (relay_1_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #1 OFF\" onclick=\"location.href='/1_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #1 ON\" onclick=\"location.href='/1_off';\"></td>"; }

                 if (relay_9_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #9 OFF\" onclick=\"location.href='/9_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #9 ON\" onclick=\"location.href='/9_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_2_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #2 OFF\" onclick=\"location.href='/2_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #2 ON\" onclick=\"location.href='/2_off';\"></td>"; }

                 if (relay_10_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #10 OFF\" onclick=\"location.href='/10_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #10 ON\" onclick=\"location.href='/10_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_3_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #3 OFF\" onclick=\"location.href='/3_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #3 ON\" onclick=\"location.href='/3_off';\"></td>"; }

                 if (relay_11_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #11 OFF\" onclick=\"location.href='/11_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #11 ON\" onclick=\"location.href='/11_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_4_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #4 OFF\" onclick=\"location.href='/4_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #4 ON\" onclick=\"location.href='/4_off';\"></td>"; }

                 if (relay_12_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #12 OFF\" onclick=\"location.href='/12_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #12 ON\" onclick=\"location.href='/12_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_5_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #5 OFF\" onclick=\"location.href='/5_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #5 ON\" onclick=\"location.href='/5_off';\"></td>"; }

                 if (relay_13_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #13 OFF\" onclick=\"location.href='/13_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #13 ON\" onclick=\"location.href='/13_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_6_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #6 OFF\" onclick=\"location.href='/6_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #6 ON\" onclick=\"location.href='/6_off';\"></td>"; }

                 if (relay_14_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #14 OFF\" onclick=\"location.href='/14_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #14 ON\" onclick=\"location.href='/14_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_7_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #7 OFF\" onclick=\"location.href='/7_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #7 ON\" onclick=\"location.href='/7_off';\"></td>"; }

                 if (relay_15_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #15 OFF\" onclick=\"location.href='/15_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #15 ON\" onclick=\"location.href='/15_off';\"></td>"; }
  web += "</tr>";
  web += "<tr>";
                 if (relay_8_state == 0)
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #8 OFF\" onclick=\"location.href='/8_on';\"></td>"; }
                 else 
                  { web += "<td align=\"left\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #8 ON\" onclick=\"location.href='/8_off';\"></td>"; }

                 if (relay_16_state == 0)
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonOFF\" value=\"RELAY #16 OFF\" onclick=\"location.href='/16_on';\"></td>"; }
                 else 
                  { web += "<td align=\"right\"><input type=\"button\" class=\"buttonON\" value=\"RELAY #16 ON\" onclick=\"location.href='/16_off';\"></td>"; }
  web += "</tr>";
  web += "</tbody> </table>";                                   
  
  web += "<table width=\"500px\" align=\"center\"> <tbody> <tr>";
  web += "<td align=\"left\"><input type=\"button\" class=\"buttonBOTTOM\" onclick=\"location.href='/all_on';\" style=\"background-image: url(data:image/png;base64,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);\"></td>";
  web += "<td align=\"center\"><input type=\"button\" class=\"buttonBOTTOM\" value=\"\" onclick=\"location.href='/';\" style=\"background-image: url(data:image/png;base64,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);\"></td>";
  web += "<td align=\"right\"><input type=\"button\" class=\"buttonBOTTOM\" onclick=\"location.href='/all_off';\" style=\"background-image: url(data:image/png;base64,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);\"></td>";
  web += "</tr> </tbody> </table>"; 
  web += "</body></html>";

  NewEvent = 1; // flag for I2C when new data is received

  return(web);
}
