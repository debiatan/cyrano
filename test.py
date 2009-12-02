#!/usr/bin/env python

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
print 'Sleeping for two seconds'
time.sleep(2)
arduino.close()
