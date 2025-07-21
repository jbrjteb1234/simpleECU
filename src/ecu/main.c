#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    cylinderSpec* spec = (cylinderSpec*) malloc( sizeof(*spec) );
    fuelInjector* injector = (fuelInjector*) malloc( sizeof(*injector) );
    camshaftLobe* lobe = (camshaftLobe*) malloc( sizeof(*lobe) );

    valveFlow* intakeValveFlowModel = (environment*) malloc(1);
    valveFlow* exhaustValveFlowModel = (environment*) malloc(1);
    friction* frictionModel = (environment*) malloc(1);
    combustion* combustionModel = (environment*) malloc(1);
    fuel* fuelModel = (environment*) malloc(1);
    environment* environmentModel = (environment*) malloc(1);

    engine* newEngine = initEngine(INLINE4, spec, injector, lobe, combustionModel, frictionModel, intakeValveFlowModel, exhaustValveFlowModel, environmentModel, fuelModel);
    return 0;
}
