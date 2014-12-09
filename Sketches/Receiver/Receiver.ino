/* Programmer: Hoang Nguyen
 * This sketch is written to receive commands from a transmitter.
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

#define LED_1 6		// Indicator LED
const uint8_t pipe_address[][6] = {"1Node"};	// this address value is too big for an literal integer,
												// that's why LL is added to convert its type to 'long long'
uint8_t got_byte;
RF24 receiver(7,8);			// Pin 7 is for Chip Enable (CE) while Pin 8 is for SPI Chip select (CSN)
void setup() {
	// Serial monitor set-up
	Serial.begin(9600);
	printf_begin();

	// Set up LED_1 for indicator output
	pinMode(LED_1, OUTPUT);
	digitalWrite(LED_1, LOW);

	// Receiver set-up
	receiver.begin();
	receiver.openReadingPipe(1,pipe_address[0]);
	receiver.startListening();	// Start listening from the receiver
	receiver.printDetails();
}

void loop() {
	while(receiver.available()){
		receiver.read(&got_byte,1);
		Serial.print("Received data: ");
		Serial.println(got_byte);
		delay(100);
	}

}

