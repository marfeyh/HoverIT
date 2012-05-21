/*!
 @file wifi_wrapper.c
 @headerfile wifi_wrapper.h
 @details This wrapper file use for convert an object-oriented C++ file to
 a functional C++ file that can include and use in main.c
 @author Ayda Monzavi
 @author Massih Mozahhebi
 */

#include <Arduino.h>
#include "searduino.h"
#include <Streaming.h>
#include <SoftwareSerial.h>
#include <WiFlySerial.h>
#include <wifi_wrapper.h>

//Rx & Tx pin 
#define ArduinoBoard_RX 22
#define ArduinoBoard_TX 23
//
#define SSID "XT910"
#define passphrase "12345678"

#define buff_size 120
char buff[buff_size];
void connect(void);
//bool connect = false;

WiFlySerial wifi = WiFlySerial(ArduinoBoard_RX,ArduinoBoard_TX);
 
int wifi_begin(){
//	Serial.begin(9600);
	Serial.println("e");
	wifi.begin();
	Serial.println("1");
	wifi.setAuthMode( WIFLY_AUTH_ADHOC);
	wifi.setJoinMode( WIFLY_JOIN_AUTO );
	wifi.setIP("192.168.42.42");
	Serial.println("2");
//	wifi.setDHCPMode( WIFLY_DHCP_ON );

	wifi.getDeviceStatus();
	//check if the device is connected ! if not, trying to reconnect
	if(!wifi.isifUp()){
		Serial.println("Wifi Started");
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
		//Serial.write(e);
	}

	//Should exit the command mode to prepare sending and recieving through network
	if(wifi.isInCommandMode()){
		wifi.exitCommandMode();
		Serial.println("Exit command mode to listen to network packets....");
	}
	return 0;
}
	
unsigned char wifi_read(){
	if (wifi_available() > 0) {
			unsigned char input = wifi.read();
			return input;
		} // if there is anything available on serial input
		return 255;
}
int wifi_write(unsigned char out){
	return wifi.write(out);
}
int wifi_available(){
	return wifi.available();
}

//Internal Function
void connect(){
  if( wifi.setSSID(SSID) ){
    Serial.println("SSID set succesfully!");
  }
//  if( wifi.setPassphrase(passphrase) ){
//    Serial.println("Passphrase set successfully");
//  }
  Serial.println("Trying to connect to network ...");

  if( wifi.join() ){
    Serial.println("Connect to network successfully !");
  }
  else{
    Serial.println("Connect to network failed !");
  }
}

