typedef struct {
    float baro_kPa;
    float ambTemp_K;
} environment;

typedef struct {
    float LHV_JpKg;              
    float stoichAFR;
    float density_kgpL;
} fuel;