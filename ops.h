#ifndef _OP_H
#define _OP_H

#include "WProgram.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
typedef void (*fp)(void);

typedef struct opdesc_t OpDesc;
struct opdesc_t{
    char* name;
    uchar code;
    fp function;
};

void build_opdesc(OpDesc* opdesc, const char* name, uchar code, fp function){
    opdesc->name = (char*) malloc((strlen(name)+1)*sizeof(char));
    strcpy(opdesc->name, name);
    opdesc->code = code;
    opdesc->function = function;
}

void list_ops(){
    digitalWrite(13, HIGH);   // sets the LED on
    Serial.write('l');
}

OpDesc* ops(){
    OpDesc* opdescs = (OpDesc*) malloc(sizeof(OpDesc)*4);
    build_opdesc(&opdescs[0], "listOps", 0, (fp)list_ops);
    build_opdesc(&opdescs[1], "pinMode", 1, (fp)pinMode);
    build_opdesc(&opdescs[2], "digitalWrite", 2, (fp)digitalWrite);
    build_opdesc(&opdescs[3], "digitalRead", 3, (fp)digitalRead);

    return opdescs;
}

#endif  // _OP_H
