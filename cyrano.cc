#include "WProgram.h"
extern "C" void __cxa_pure_virtual() {}  // Bug in avr-libc ??

#include "ops.h"

const int LED = 13;

typedef union int_t Int;
union int_t{
    uchar bytes[2];
    uint value;
};

uchar read_byte(){
    int aux;
    do aux = Serial.read(); while(aux == -1);
    return (uchar)aux;
}

uint read_word(){
    Int word;
    word.bytes[0] = read_byte();
    word.bytes[1] = read_byte();
    return word.value;
}

void call(uint cmd, uint args[3]){
    switch((OpType)cmd){
      case LIST_OPS: list_ops(); break;
      default: Serial.write(cmd);
               break;
    }
}

// from the python side of things, use the struct library

int main(void) {
	init();
    Serial.begin(115200);

    pinMode(LED, OUTPUT);

    uint cmd;
    uint args[3];

	while(1){
        if(Serial.available()>0){
            cmd = read_word();
            for(int i = 0; i<3; ++i) args[i] = read_word();
            call(cmd, args);    // process char[] reply
        }
    }

	return 0;
}

