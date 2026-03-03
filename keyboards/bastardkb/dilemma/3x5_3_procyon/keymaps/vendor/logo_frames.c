#include "logo_frames.h"
#include "logo.h"

// Array de frames de prueba (2 frames idénticos)
const lv_img_dsc_t* logo_frames[] = {
    &logo_img,
    &logo_img
};

// Número de frames
const uint8_t logo_frame_count = sizeof(logo_frames) / sizeof(logo_frames[0]);