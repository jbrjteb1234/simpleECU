#include <stdint.h>
#include <stdlib.h>

typedef struct {
    float bore_mm;
    float rodLength_mm;
    float pistonHeight_mm;
    float strokeLength_mm;
    float clearanceVolume_cc;
} cylinderSpec;

typedef struct {
    float staticFlow_cc;
    float fuelDensity;
    float deadTime_ms;
} fuelInjector;

typedef struct{
    float open_deg;
    float close_deg;
    float maxLift_mm;
} camshaftLobe;

typedef struct {
    cylinderSpec* spec;

    //crank offset
    uint16_t crankOffset_deg;

    //camshaft offset
    uint16_t camshaftOffset_deg;

    //physical data
    float fromTDC_deg;
    float pistonPos_mm;
    float volume_cc;

    //cylinder gas data
    float pressure_kPa;
    float temp_K;
    float massAir_kg;
    float massFuel_kg;

    //combustion data
    float burn_frac;        
    float heat_release_J;   

    //valve data
    float intakeLift_mm;
    float exhaustLift_mm;

    float knock_dB;

    fuelInjector* injector;
    camshaftLobe* lobe;

} cylinder;

cylinder* initCylinders(cylinderSpec*, fuelInjector*, camshaftLobe*, uint16_t);

void setCamCrankOffset(cylinder*, uint16_t, uint16_t);

