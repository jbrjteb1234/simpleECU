typedef struct {
    const float bore_mm;
    const float rodLength_mm;
    const float pistonHeight_mm;
    const float domeVolume_cc;
    const int crankOffset_deg;

    const float intakeValveDia_mm;
    const float exhaustValveDia_mm;
    const float intakeValveLiftMax_mm;
    const float exhaustValveLiftMax_mm;

} cylinderSpec;

typedef struct {
    const cylinderSpec spec;

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

} cylinder;

typedef struct {

} injector;

