#ifndef _OP_H
#define _OP_H

#include "WProgram.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned short int uint;

typedef enum{LIST_OPS=0, PIN_MODE=1, DIGITAL_WRITE=2, DIGITAL_READ=3} OpType;


void list_ops(){
    digitalWrite(13, HIGH);   // sets the LED on
    Serial.write("l\n");
}

/*
OpDesc* ops(){
    OpDesc* opdescs = (OpDesc*) malloc(sizeof(OpDesc)*4);
    build_opdesc(&opdescs[0], "listOps", 0, (fp)list_ops);
    build_opdesc(&opdescs[1], "pinMode", 1, (fp)pinMode);
    build_opdesc(&opdescs[2], "digitalWrite", 2, (fp)digitalWrite);
    build_opdesc(&opdescs[3], "digitalRead", 3, (fp)digitalRead);

    return opdescs;
}
*/

#endif  // _OP_H
