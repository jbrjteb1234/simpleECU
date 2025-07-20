#include "cylinder.h"
#include <stdint.h>
#include "models/combustion.h"
#include "friction.h"
#include "valveFlow.h"

typedef struct {
    float volume_L;           
    float pressure_kPa;
    float temp_K;
    float massAir_kg;
} manifold;

typedef struct{
    cylinder* cylinders;
    
    manifold intake;
    manifold exhaust;

    combustion combustionModel;
    friction frictionModel;
    valveFlow intakeValveFlowModel, exhaustValveFlowModel;

    const float crankOffset_mm;
    const float fuelRailPressure_kPa;

    float crankAngle_deg;
    float camAngle_deg;
    float throttlePos_frac;

} engine;

typedef enum {
    INLINE4,
    INLINE5,
    INLINE6,
} engineLayout;

engine* initEngine(engineLayout layout, cylinderSpec* spec);

