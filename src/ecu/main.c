#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

void main(void){

    cylinderSpec* spec = (cylinderSpec*) malloc( sizeof(*spec) );

    engine* newEngine = initEngine(INLINE4, spec);
    return 0;
}
