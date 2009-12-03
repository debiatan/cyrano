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

#include "WProgram.h"
#include "ops.h"
using namespace std;

extern "C" void __cxa_pure_virtual() {}  // Bug in avr-libc ??

// Beware of endianness. MSB first.

uchar read_byte(){
    while(!Serial.available());
    return Serial.read();
}

uint read_word(){
    return ((uint)read_byte())*256 + (uint)read_byte();
}

void write_word(uint value){
    Serial.write((uchar)(value/256));
    Serial.write((uchar)(value%256));
}

uint call(uint cmd, uint args[3]){
    return (functions[cmd])(args[0], args[1], args[2]);
}

int main(void) {
	init();
    Serial.begin(115200);

    uint cmd;
    uint args[3];

	while(1){
        if(Serial.available() > 0){
            cmd = read_word();
            for(int i = 0; i<n_args[cmd]; ++i) args[i] = read_word();
            write_word(call(cmd, args));
        }
    }

	return 0;
}
