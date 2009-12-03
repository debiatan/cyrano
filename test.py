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

time.sleep(2)
print 'Setting pin'
print arduino.pinMode(13, OUTPUT)
print 'Reading value'
print arduino.digitalRead(13)
print 'Writting value'
print arduino.digitalWrite(13, HIGH)
print 'Reading value'
print arduino.digitalRead(13)
print 'Sleeping for two seconds'
time.sleep(2)
arduino.close()
