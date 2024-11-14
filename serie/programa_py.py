import serial
import struct
from time import sleep

arduino = serial.Serial(port = "/dev/cu.usbserial-1420", baudrate = 9600)

estado_led = False

while True:
    datos_tx = struct.pack('?', estado_led)

    arduino.write(datos_tx)

    if estado_led == True:
        estado_led = False
    else:
        estado_led = True

    sleep(1)

