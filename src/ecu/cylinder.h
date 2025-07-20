#include <stdint.h>

typedef struct {
    const float bore_mm;
    const float rodLength_mm;
    const float pistonHeight_mm;
    const float strokeLength_mm;
    const float clearanceVolume_cc;
} cylinderSpec;

typedef struct {
    cylinderSpec* spec;

    //crank offset
    int crankOffset_deg;

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

    fuelInjector injector;
    camshaftLobe lobe;

} cylinder;

typedef struct {
    float staticFlow_cc;
    float fuelDensity;
    float deadTime_ms;
} fuelInjector;

typedef struct{
    float open_deg;
    float close_deg;
    float maxLift_mm;
    float camshaftOffset_deg;
} camshaftLobe;

cylinder* initCylinders(cylinderSpec*, uint16_t);

void setCrankOffset(cylinder*, uint16_t);

void setCamOffset(camshaftLobe*, uint16_t);

