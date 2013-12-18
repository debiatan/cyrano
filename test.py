#!/usr/bin/env python
# Copyright (c) 2009 Miguel Lechon
# 
#This file is part of Cyrano. Cyrano is free software: you can redistribute it
#and/or modify it under the terms of the GNU General Public License as published
#by the Free Software Foundation, either version 3 of the License, or (at your 
#option) any later version.
#
#Cyrano is distributed in the hope that it will be useful, but WITHOUT ANY 
#WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
#PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License along with 
#Cyrano. If not, see <http://www.gnu.org/licenses/>.


from pyrano import *
import time

arduino = Pyrano('/dev/ttyUSB0')

time.sleep(2) # Device is reset on incoming connection; wait for cyrano to wake

print('Pin 13: ', arduino.digitalRead(13))  # Read digital 
arduino.pinMode(13, OUTPUT)
arduino.digitalWrite(13, HIGH)              # Write digital 
print('Pin 13: ', arduino.digitalRead(13))  # Read digital
print('Pin 0:', arduino.analogRead(0))      # Read analog
arduino.analogWrite(9, 100)                 # PWM output
arduino.close()
