typedef struct {
    float FMEP0_kPa;             // constant offset
    float k_speed_kPaPerkrpm;    // linear term vs rpm
    float k_bmep_frac;           // load fraction term
} friction;