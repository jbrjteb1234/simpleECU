#include "cylinder.h"
#include <stdint.h>
#include "models/combustion.h"
#include "models/friction.h"
#include "models/valveFlow.h"
#include "models/environment.h"

typedef struct {
    float volume_L;           
    float pressure_kPa;
    float temp_K;
    float massAir_kg;
} manifold;

typedef struct{

    cylinderSpec* spec;
    fuelInjector* injector;
    cylinder* cylinders;
    camshaftLobe* lobe;
    
    manifold intake;
    manifold exhaust;

    combustion combustionModel;
    friction frictionModel;
    valveFlow intakeValveFlowModel, exhaustValveFlowModel;
    environment environmentModel;
    fuel fuelModel;

    const float crankOffset_mm;
    const float fuelRailPressure_kPa;

    float crankAngle_deg;
    float camAngle_deg;
    float throttlePos_frac;

    float rpm;
    float crankInertia_kgm2;

} engine;

typedef enum {
    INLINE4,
    INLINE5,
    INLINE6,
} engineLayout;

engine* initEngine(engineLayout layout, cylinderSpec* spec, fuelInjector* injector, camshaftLobe* lobe, combustion* combustionModel, friction* frictionModel,  valveFlow* intakeValveFlowModel, valveFlow* exhaustValveFlowModel, environment* environmentModel, fuel* fuelModel);

