import serial
import math
from time import sleep


class tag:
  def __init__(self, identifier, x, y, z):
    self.identifier = identifier
    self.x = x
    self.y = y
    self.z = z
  def __str__(self):
    # return f"Tag = {self.identifier}, x={self.x}, y={self.y}, z={self.z}"
    return f"{self.identifier},{self.x},{self.y},{self.z}\n"

ser = serial.Serial("COM9", 38400)
tagsDict = dict()
coasterId = "8312"
forwardSpeed = 0.5 # meter/second
rotationSpeed = 10 # degrees/second
def signal(val):
    ser.write(chr(val).encode())

def getTagLocations():
  tagsDict = dict()
  tagLocationFile = open("taglocation.txt", "r")
  locations = tagLocationFile.readlines()
  for location in locations:
    loc = location.split(",")
    thisTag = tag(loc[0], loc[1], loc[2] ,loc[3])
    tagsDict["Tag"+thisTag.identifier].append(thisTag)

def getAngle(coasterId, callerId):
  x1 = tagsDict("Tag"+coasterId).x
  y1 = tagsDict("Tag"+coasterId).y
  
  x2 = tagsDict("Tag"+callerId).x
  y2 = tagsDict("Tag"+callerId).y
  
  signal(2)
  sleep(2)
  getTagLocations()
  
  x3 = tagsDict("Tag"+coasterId).x
  y3 = tagsDict("Tag"+coasterId).y
  
  theta = math.degrees(math.atan2(y3-y1, x3-x1) - math.atan2(y2-y1, x2-x1)) 
  angle = theta if theta >= 0 else theta+360
  return angle #

def getDistance(coasterId, callerId):
  getTagLocations()
  x1 = tagsDict("Tag"+coasterId).x
  y1 = tagsDict("Tag"+coasterId).y
  
  x2 = tagsDict("Tag"+callerId).x
  y2 = tagsDict("Tag"+callerId).y
  distance = math.sqrt((x2-x1)**2 + (y2-y1)**2)
  return distance
  
def getDirectionTime(coasterId, callerId):
  costerTag = tagsDict["Tag"+coasterId]
  callerTag = tagsDict["Tag"+callerId]
  angle = getAngle(coasterId, callerId)
  distance = getDistance(coasterId, callerId)
  forwardTime = distance / forwardSpeed
  rotateTime = angle / rotationSpeed
  return rotateTime, forwardTime

inputFile = 'C:\Users\Omar Areiqat\Documents\Serial_Output\com_COM9_COM9  (USB Serial Device (COM9)).log'
file = open(inputFile, "r")
file.readlines()



while 1:
  line = file.readline()
  if(line != ""):
    lineSplit = line.split(" ")
    callerId, command = lineSplit[0], int(lineSplit[1])
    if command == 1:
        rotateTime, forwardTime = getDirectionTime(coasterId, callerId)
        signal(9) # rotate counter clockwise
        sleep(rotateTime)
        signal(0) # stop
        signal(2)
        sleep(forwardTime) # forward
        signal(0) #stop
        # go to location
        
file.close()