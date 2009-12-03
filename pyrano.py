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

import serial

INPUT = 0
OUTPUT = 1
LOW = 0
HIGH = 1

class Pyrano:
    __PIN_MODE = 0
    __DIGITAL_READ = 1
    __DIGITAL_WRITE = 2
    def __init__(self, port, baudrate=115200):
        self.serial = serial.Serial(port, baudrate)

    def __read_word(self):
        return ord(self.serial.read())*256 + ord(self.serial.read())

    def __write_word(self, value):
        self.serial.write(chr(value/256))
        self.serial.write(chr(value%256))

    def __write_words(self, values):
        for value in values:
            self.__write_word(value)

    def pinMode(self, pin, mode):
        self.__write_words([self.__PIN_MODE,pin,mode])
        return self.__read_word()

    def digitalRead(self, pin):
        self.__write_words([self.__DIGITAL_READ,pin])
        return self.__read_word()

    def digitalWrite(self, pin, value):
        self.__write_words([self.__DIGITAL_WRITE,pin,value])
        return self.__read_word()

    def close(self):
        self.serial.close()
        return True

    def __del__(self):
        self.serial.close()

