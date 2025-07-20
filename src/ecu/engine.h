#include "cylinder.h"
#include <stdint.h>

typedef struct{
    cylinder* cylinders;
    
    const float crankOffset_mm;
    const float fuelRailPressure_kPa;

    float crankAngle_deg;

} engine;

typedef enum {
    INLINE4,
    INLINE5,
    INLINE6,
} engineLayout;

engine* initEngine(engineLayout layout, cylinderSpec* spec);

