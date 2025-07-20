#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    cylinderSpec* spec = (cylinderSpec*) malloc( sizeof(*spec) );
    fuelInjector* injector = (fuelInjector*) malloc( sizeof(*injector) );
    camshaftLobe* lobe = (camshaftLobe*) malloc( sizeof(*lobe) );

    engine* newEngine = initEngine(INLINE4, spec, injector, lobe);
    return 0;
}
