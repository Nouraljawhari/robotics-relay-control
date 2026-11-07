# Robotics Relay Control

Arduino project that controls 3 relays over Bluetooth and reads
temperature/humidity (DHT11) and ambient light (LDR).

## Hardware
- Arduino board
- HC-05/HC-06 Bluetooth module
- DHT11 sensor (pin 7)
- LDR (A0)
- 3-channel relay module (pins 4, 5, 6)

## Commands (sent over Bluetooth)
`1 ON`, `1 OFF`, `2 ON`, `2 OFF`, `3 ON`, `3 OFF`

