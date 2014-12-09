This project is created to provide schematics, PCB layout as well as Arduino sketches for both transmitter and receiver used in controlling Electric Skateboard.
CAUTION: Used at your own risk.

How to wire up nRF24 breakout board to Arduino Uno:
nRF24 ----- Uno
  1   ----- GND
  2   ----- VCC
  3   -----  7 (Chip enable)
  4   -----  8 (SPI Chip select)
  5   -----  13 (SPI Clock)
  6   -----  11 (SPI MOSI)
  7   -----  12 (SPI MISO)

Hoang Nguyen
