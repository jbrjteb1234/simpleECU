#include "engine.h"

engine* initEngine(engineLayout layout, cylinderSpec* spec){
    engine* newEngine = (engine*)malloc(sizeof(engine));

    switch (layout){
    case INLINE4:
        newEngine->cylinders = initCylinders(spec, 4);
        setCrankOffset(&newEngine->cylinders[1], 180);
        setCrankOffset(&newEngine->cylinders[2], 180);

        setLobeOffset(&(newEngine->cylinders[0].lobe), 0);
        setLobeOffset(&(newEngine->cylinders[1].lobe), 270);
        setLobeOffset(&(newEngine->cylinders[2].lobe), 90);
        setLobeOffset(&(newEngine->cylinders[3].lobe), 180);
        break;
    
    default:
        break;
    }

    return newEngine;
}