#include "cylinder.h"

void setCrankOffset(cylinder* cyl, uint16_t offset){
    cyl->crankOffset_deg = offset;
}

void setLobeOffset(camshaftLobe* lobe, uint16_t offset){
    lobe->camshaftOffset_deg = (float)offset;
}

cylinder* initCylinders(cylinderSpec* spec, uint16_t numCylinders){
    
    cylinder* newCylinders = (cylinder*)malloc(numCylinders * sizeof(*newCylinders));

    for(int i=0; i<numCylinders; ++i){
        newCylinders[i].spec = spec;
        newCylinders[i].crankOffset_deg = 0;
        newCylinders[i].lobe.camshaftOffset_deg = 0;
    }

    return newCylinders;
}