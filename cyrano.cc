#include "WProgram.h"
extern "C" void __cxa_pure_virtual() {}  // Bug in avr-libc ??

#include "ops.h"

const int LED = 13;


typedef union int_t Int;
union int_t{
    uchar bytes[2];
    uint value;
};

uint read_word(){
    Int word;
    word.bytes[0] = Serial.read();
    word.bytes[1] = Serial.read();

    return word.value;
}

void call(uint cmd, uint args[3]){
    //switch((OpType)cmd){
    switch(cmd%256){    // Problem in the first byte!!!
      case 0: list_ops(); break;
      default: Serial.write(cmd);
               break;
    }
}

// from the python side of things, use the struct library

int main(void) {
	init();
//	setup();
    Serial.begin(115200);

    pinMode(LED, OUTPUT);

    //OpDesc* opdescs = ops();

    uint cmd;
    uint args[3];

	while(1){
        if(Serial.available()>0){
            cmd = read_word();
            for(int i = 0; i<3; ++i) args[i] = read_word();
            call(cmd, args);    // process char[] replay
        }
    }

#if 0
        digitalWrite(LED, HIGH);   // sets the LED on
        delay(1000);                  // waits for a second
        digitalWrite(LED, LOW);    // sets the LED off
        delay(1000);
#endif
        
	return 0;
}

