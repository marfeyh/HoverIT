/*************************************************
 * Partly auto generated C file from wifi//wifi.ino
 *    (C) is a mix of original Arduino author's codes and Henrik Sandklef
 */

#include <Arduino.h>
#include "searduino.h"

/*** End of auto generated part ***/













/*
Describtion : try to connect to specified wifi network,and send and recieve data
 Requirement :
 Libraries :
 *WiFlySerial
 *PString
 *SoftwareSrial
 *Streaming
 Hardware :
 *WiFly GSX 802.11b/g Serial Module
 
 Author :
 Massih Mozahhebi,Aida Monzavi
 */

#include <SoftwareSerial.h>
#include <WiFlySerial.h>
#include <Streaming.h>

#define ArduinoBoard_RX 2
#define ArduinoBoard_TX 3

#define SSID "massih"
#define passphrase "12345678"

#define buff_size 120
char buff[buff_size];

//
int led1 = 12;
int led2 = 8;
//
WiFlySerial wifi(ArduinoBoard_RX,ArduinoBoard_TX);

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial communication with wifi shield Started !");
  wifi.begin();
  Serial.println("Wifi module Started !");
  //Network Setting
  wifi.setAuthMode( WIFLY_AUTH_WPA2_PSK);
  wifi.setJoinMode(  WIFLY_JOIN_AUTO );
  wifi.setDHCPMode( WIFLY_DHCP_ON );

  wifi.getDeviceStatus();
  //check if the device is connected ! if not, trying to reconnect
  if(!wifi.isifUp()){
    connect();
  }
  else{
    Serial.println(wifi.getIP(buff,buff_size));
    Serial.println(wifi.getMAC(buff,buff_size));
  }

  wifi.closeConnection();
  wifi.flush();
  while (wifi.available() ){
    char e = wifi.read();
    Serial.write(e);
  }

  //Should exit the command mode to prepare sending and recieving through network
  if(wifi.isInCommandMode()){
    wifi.exitCommandMode();
     Serial.println("Exit command mode to listen to network packets....");
   }

}

void connect(){
  if( wifi.setSSID(SSID) ){
    Serial.println("SSID set succesfully!");
  }
  if( wifi.setPassphrase(passphrase) ){
    Serial.println("Passphrase set successfully");
  }
  Serial.println("Trying to connect to network ...");

  if( wifi.join() ){
    Serial.println("Connect to network successfully !");
  }
  else{
    Serial.println("Connect to network failed !");
  }
}
char bs;
char bw;
void loop(){

  while(wifi.available() >= 1){
    bw = wifi.read();
    if(bw == 12){
      digitalWrite(led1,HIGH);  
    }else if(bw == 13){
      digitalWrite(led2,HIGH);
    }
    Serial.write(bw);
  }
  if(Serial.available()){
    bs = Serial.read();
    wifi.write(bs);
  }
}




/* Part of this file has been auto generated from wifi//wifi.ino, 
 * which is part of the Arduino source code *******/
