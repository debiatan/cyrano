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

# Example file for getting distance readouts from the maxbotix LV-MaxSonar-EZ4 
# ultrasonic range finder
# Connect:
# Arduino           EZ4
# =======           ===
# GND               GND
# 5V                +5
# Digital13         RX
# Analog0           AN

from pyrano import *
import time

arduino = Pyrano('/dev/ttyUSB0')

time.sleep(2) # Device is reset on incoming connection; wait for cyrano to wake

arduino.pinMode(13, OUTPUT)
arduino.digitalWrite(13, HIGH)
#arduino.digitalWrite(13, LOW) #to stop reading

while True:
    time.sleep(30/1000000)
    readout = arduino.analogRead(0)
    mV = (readout/1024.)*5000
    distance = (mV/9.8)*2.54
    print(readout, mV, 'mV', distance, 'cm')
    time.sleep(0.5)

arduino.close()
