In this project user uses this terminal to send data from the first Bluetooth device to the Master microcontroller (Second Bluetooth Device)
Here HC05 1 uses Serial COM1, HC05 Serial COM2 and both COM ports are paired together so each port can see the other.
HC05 2 receives data from HC05 1 through wireless serial communication and then resend it to MCU1 through UART.

Atmega32 microcontroller works as  a master that receives data from HC05 2 through UART and resend it to MCU2 through SPI protocol
finally the On/Off device 
It can be any device, here I have used LED connected to slave MCU2, so when user writes “on#” using virtual terminal or mobile APP and sends it, slave Enables the LED and if  user sends “off#” slave Turns the device off.
