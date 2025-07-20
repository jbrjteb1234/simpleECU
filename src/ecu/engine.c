#include "engine.h"

engine* initEngine(engineLayout layout, cylinderSpec* spec, fuelInjector* injector, camshaftLobe* lobe){

    engine* newEngine = (engine*)malloc(sizeof(engine));
    newEngine->lobe = lobe;
    newEngine->injector = injector;
    newEngine->spec = spec;
    

    switch (layout){
    case INLINE4:
        newEngine->cylinders = initCylinders(spec, injector, lobe, 4);
        setCamCrankOffset(&newEngine->cylinders[0], 0,      0);
        setCamCrankOffset(&newEngine->cylinders[1], 180,    270);
        setCamCrankOffset(&newEngine->cylinders[2], 180,    90);
        setCamCrankOffset(&newEngine->cylinders[3], 0,      180);

        break;
    
    default:
        break;
    }

    return newEngine;
}