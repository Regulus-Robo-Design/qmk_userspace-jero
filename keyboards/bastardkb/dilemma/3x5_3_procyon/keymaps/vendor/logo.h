#ifndef LOGO_H
#define LOGO_H

#include <stdint.h>

// Función para reproducir la animación de frames del logo
// ms_per_frame: duración de cada frame en milisegundos
// repeat: número de veces que se repite la animación (0 = repetir indefinidamente)
void logo_play_animation(uint32_t ms_per_frame, uint8_t repeat);

#endif // LOGO_H