/* Programmer: Hoang Nguyen
 * This sketch is written to send control signal to a receiver.
 * Both transmitter and receiver are using the nRF24L01+ transceiver IC from Nordic.
 * The main purpose of this system is to control a RC electric skateboard.
 * The library used in this sketch is RF24 library written by Coliz <maniacbug@ymail.com>,
 * which can be found at https://github.com/maniacbug/RF24
 * CAUTION: use this sketch with your own risk. I take no responsibility if this program causes any damage
 */

#include "RF24.h"
#include "nRF24L01.h"
#include "printf.h"
#include <SPI.h>

#define BUTTON_1 A0		// everytime this button clicked will trigger LED changing in the receiver

const uint8_t pipe_address[][6] = {"1Node"};	// this address value is too big for an literal integer,
												// that's why LL is added to convert its type to 'long long'
uint8_t ON = 0x01;
uint8_t OFF = 0x00;
RF24 transmitter(7,8);		// Pin 7 is for Chip Enable (CE) while Pin 8 is for SPI Chip select (CSN)
void setup() {
	// Set up Serial monitor
	Serial.begin(57600);
	printf_begin();

	// Set up BUTTON_1 as input
	pinMode(BUTTON_1, INPUT_PULLUP);
	transmitter.begin();	// Set up basic parameters for RF24
	transmitter.openWritingPipe(pipe_address[0]);
	transmitter.powerUp();
	transmitter.printDetails(); // Print basic parameters of RF24
	delay(100);
}

void loop() {
	if (digitalRead(BUTTON_1)){
		if (transmitter.write(&ON,1)){
			Serial.println("ON Transfer succeed!");
		}
	}
	else
		if (transmitter.write(&OFF,1)) {
			Serial.println("OFF Transfer succeed");
		}
	delay(100);
}


