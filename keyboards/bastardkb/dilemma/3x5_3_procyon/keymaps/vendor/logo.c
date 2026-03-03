#include "logo.h"
#include "logo_frames.h"
#include "lvgl.h"

// Función para reproducir animación de frames
// ms_per_frame = duración de cada frame en milisegundos
// repeat = número de veces que se repite la animación (0 = indefinido)
void logo_play_animation(uint32_t ms_per_frame, uint8_t repeat)
{
    lv_obj_t *img = lv_img_create(lv_scr_act());  // crear objeto imagen
    lv_obj_center(img);                            // centrar en pantalla

    uint32_t frame_index = 0;
    uint8_t loops = 0;

    uint32_t start_tick = lv_tick_get();

    while (repeat == 0 || loops < repeat)
    {
        // Cambiar la imagen actual
        lv_img_set_src(img, logo_frames[frame_index]);
        lv_timer_handler();  // actualizar LVGL

        // Esperar ms_per_frame milisegundos
        uint32_t tick_start = lv_tick_get();
        while (lv_tick_elaps(tick_start) < ms_per_frame)
        {
            lv_timer_handler();
        }

        // Pasar al siguiente frame
        frame_index++;
        if (frame_index >= logo_frame_count)
        {
            frame_index = 0;  // reiniciar frames
            loops++;
        }
    }

    // Al terminar, eliminar objeto de pantalla
    lv_obj_del(img);
}