# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM4', baudrate=115200, timeout=1)
def write_read(x,y,z):
    arduino.write(bytes(x, 'utf-8'))
    arduino.write(bytes(y, 'utf-8'))
    arduino.write(bytes(z, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    x1 = "0"
    y1 = "0"
    z1 = "0"
    value = write_read(x1+"#",y1+"@",z1+"$")
    print(value) # printing the value
    print(type(value))
