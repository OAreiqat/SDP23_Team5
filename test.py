# import bluetooth
from time import sleep
# target_name = "My Phone"
# target_address = None

# nearby_devices = bluetooth.discover_devices()

# for bdaddr in nearby_devices:
#     if target_name == bluetooth.lookup_name( bdaddr ):
#         target_address = bdaddr
#         break

# if target_address is not None:
#     print ("found target bluetooth device with address ", target_address)
# else:
#     print ("could not find target bluetooth device nearby")

import serial

serialPort = serial.Serial(port='COM8', baudrate=9600, timeout=0, parity=serial.PARITY_EVEN, stopbits=1)
size = 1024
ser = serial.Serial("COM7", 38400)
def signal(val):
    ser.write(chr(val).encode())
while 1:
    serialPort.write(chr(5).encode())
    sleep(1)
    
    # serialPort.write(bytes(b'your_commands'))
    # serialPort.write("%01#RDD0010000107**\r".encode()) 
    # serialPort.write('hello'.encode('utf-8'))
    
    
    # signal(5)
    # data = serialPort.readline(size)

    # if data:
    #     print(data)