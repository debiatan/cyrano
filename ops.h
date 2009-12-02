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

typedef uint (*fp)(uint, uint, uint);
 
fp functions[3] = {
    (fp)pin_mode, (fp)digital_read, (fp)digital_write
};

#endif  // _OPS_H
