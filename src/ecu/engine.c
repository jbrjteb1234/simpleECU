#include "engine.h"

engine* initEngine(engineLayout layout, cylinderSpec* spec, fuelInjector* injector, camshaftLobe* lobe, combustion* combustionModel, friction* frictionModel,  valveFlow* intakeValveFlowModel, valveFlow* exhaustValveFlowModel, environment* environmentModel, fuel* fuelModel){

    engine* newEngine = (engine*)malloc(sizeof(engine));

    newEngine->spec = *spec;

    newEngine->injector = *injector;
    newEngine->lobe = *lobe;
    newEngine->combustionModel = *combustionModel;
    newEngine->frictionModel = *frictionModel;
    newEngine->intakeValveFlowModel = *intakeValveFlowModel;
    newEngine->exhaustValveFlowModel = *exhaustValveFlowModel;
    newEngine->environmentModel = *environmentModel;
    newEngine->fuelModel = *fuelModel;    

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