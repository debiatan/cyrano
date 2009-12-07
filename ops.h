/* Copyright (c) 2009 Miguel Lechon */
/* 
This file is part of Cyrano. Cyrano is free software: you can redistribute it 
and/or modify it under the terms of the GNU General Public License as published
by the Free Software Foundation, either version 3 of the License, or (at your 
option) any later version.

Cyrano is distributed in the hope that it will be useful, but WITHOUT ANY 
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with 
Cyrano. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _OPS_H
#define _OPS_H

#include "WProgram.h"

typedef unsigned char uchar;
typedef unsigned short int uint;

uint pin_mode(uint pin, uint mode, uint){ // Input: 0, Output: 1
    pinMode(pin, mode);
    return 0;
}

uint digital_read(uint pin, uint, uint){
    return digitalRead(pin);
}

uint digital_write(uint pin, uint value, uint){
    digitalWrite(pin, value);
    return 0;
}

uint analog_reference(uint type, uint, uint){
    analogReference(type);
    return 0;
}

uint analog_read(uint pin, uint, uint){
    return analogRead(pin);
}

uint analog_write(uint pin, uint value, uint){
    analogWrite(pin, value);
    return 0;
}

typedef uint (*fp)(uint, uint, uint);
 
fp functions[] = {
    (fp)pin_mode, (fp)digital_read, (fp)digital_write,
    (fp)analog_reference, (fp)analog_read, (fp)analog_write
};

int n_args[] = {
    /*pin_mode*/ 2, /*digital_read*/ 1, /*digital_write*/ 2,
    /*analog_reference*/ 1, /*analog_read*/ 1, /*analog_write*/ 2
};

inline uint call(uint cmd, uint args[3]){
    return (functions[cmd])(args[0], args[1], args[2]);
}

#endif  // _OPS_H
