#include "WProgram.h"
#include "ops.h"
using namespace std;

extern "C" void __cxa_pure_virtual() {}  // Bug in avr-libc ??

typedef union int_t Int;
union int_t{
    uchar bytes[2];
    uint value;
};

uchar read_byte(){
    while(!Serial.available());
    return Serial.read();
}

uint read_word(){
    Int word;
    word.bytes[1] = read_byte();
    word.bytes[0] = read_byte();
    return word.value;
}

void write_word(uint w){
    Int word;
    word.value = w;
    Serial.write(word.bytes[1]);
    Serial.write(word.bytes[0]);
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
            for(int i = 0; i<3; ++i) args[i] = read_word();
            write_word(call(cmd, args));
        }
    }

	return 0;
}
