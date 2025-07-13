#include "cylinder.h"

typedef struct{
    cylinder* cylinders[4];
    const float crankOffset_mm;
    
    float crankAngle_deg;
} engine;