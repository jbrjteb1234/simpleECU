typedef struct {
    float baro_kPa;
    float ambTemp_K;
} Env;

typedef struct {
    float LHV_JpKg;              
    float stoichAFR;
    float density_kgpL;
} FuelProps;