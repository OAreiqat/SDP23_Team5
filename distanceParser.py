import os
import sys
import re
class tag:
  def __init__(self, identifier, x, y, z):
    self.identifier = identifier
    self.x = x
    self.y = y
    self.z = z
  def __str__(self):
    # return f"Tag = {self.identifier}, x={self.x}, y={self.y}, z={self.z}"
    return f"{self.identifier},{self.x},{self.y},{self.z}\n"
    

  
filename = '/home/omar/SDP/com_COM8_11_29_2022_160454.log'
tags = []


TC404 = tag("C404", 0, 0 ,0)
T8312 = tag("8312", 0, 0 ,0)
tagsDict = dict(TagC404 = TC404, Tag8312 = T8312)
tags.append(TC404)
tags.append(T8312)

lineNum = 0


file = open(filename, "r")
allLines = file.readlines()
numLines = len(allLines)



for line in allLines:
    # skip bad lines
    lineNum+=1
    if lineNum < 15: continue
    elif lineNum > numLines-20: break
    #  split text    
    lineSplit = line.split('  ')[1].split(',')
    tagName, x, y, z, qualityLevel = lineSplit[2], lineSplit[3], lineSplit[4], lineSplit[5], int(lineSplit[6])
    
    if x !="nan" and y !="nan" and z !="nan" and qualityLevel > 80:
        # Update Value
        tagsDict["Tag"+str(tagName)].x = x
        tagsDict["Tag"+str(tagName)].y = y
        tagsDict["Tag"+str(tagName)].z = z
        
        # Export Location
        outputfile = open("taglocation.txt", "w")
        for item in tagsDict:
            outputfile.write(str(tagsDict[item]))
            print(str(tagsDict[item]))
        outputfile.close()
        
while 1:
  line = file.readline()
  if(line != ""):
    lineSplit = line.split('  ')[1].split(',')
    tagName, x, y, z, qualityLevel = lineSplit[2], lineSplit[3], lineSplit[4], lineSplit[5], int(lineSplit[6])
    
    if x !="nan" and y !="nan" and z !="nan" and qualityLevel > 80:
        # Update Value
        tagsDict["Tag"+str(tagName)].x = x
        tagsDict["Tag"+str(tagName)].y = y
        tagsDict["Tag"+str(tagName)].z = z
        
        # Export Values
        outputfile = open("taglocation.txt", "w")
        for item in tagsDict:
            outputfile.write(str(tagsDict[item]))
            print(str(tagsDict[item]))
        outputfile.close()
file.close()

