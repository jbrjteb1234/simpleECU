typedef struct {
    float wiebe_a;            // shape
    float wiebe_m;            // form
    float burn_duration_deg;  // Δθb
    float ignition_delay_deg; // θd
} combustion;

typedef struct {
    float cp_JpKgK;
    float cv_JpKgK;
    float gamma;              // cp/cv
} gas;