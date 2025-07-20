#include "cylinder.h"

void setCamCrankOffset(cylinder* cyl, uint16_t crankOffset, uint16_t camOffset){
    cyl->crankOffset_deg = crankOffset;
    cyl->camshaftOffset_deg = camOffset;
}

cylinder* initCylinders(cylinderSpec* spec, fuelInjector* injector, camshaftLobe* lobe, uint16_t numCylinders){
    
    cylinder* newCylinders = (cylinder*)malloc(numCylinders * sizeof(*newCylinders));

    for(int i=0; i<numCylinders; ++i){
        newCylinders[i].spec = spec;
        newCylinders[i].crankOffset_deg = 0;
        newCylinders[i].camshaftOffset_deg = 0;
        newCylinders[i].injector = injector;
        newCylinders[i].lobe = lobe;
    }

    return newCylinders;
}