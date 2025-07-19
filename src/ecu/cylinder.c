#include "cylinder.h"



void setInitialOffset(cylinder* cyl, uint8_t order){
    cyl->crankOffset_deg = (order-1)*180;
}

cylinder* initCylinders(cylinderSpec* spec, uint8_t numCylinders){
    
    cylinder* newCylinders = (cylinder*)malloc(numCylinders * sizeof(*newCylinders));

    for(int i=0; i<numCylinders; ++i){
        newCylinders[i].spec = spec;
        newCylinders[i].crankOffset_deg = 0;
    }

    return newCylinders;
}