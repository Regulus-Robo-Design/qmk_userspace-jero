#include "logo.h"
#include "logo_frames.c"  // contiene la imagen m000_map y el descriptor 0000
#include <stdint.h>
#include <stdbool.h>

// Duración del logo en milisegundos
#define LOGO_DISPLAY_MS 2000

void logo_show_frame(void) {
    // Crear un objeto de imagen temporal
    lv_obj_t *logo_img_obj = lv_img_create(lv_scr_act()); // usar pantalla actual
    lv_img_set_src(logo_img_obj, &0000);                 // usar el descriptor de logo_frames.c
    lv_obj_center(logo_img_obj);                         // centrar en pantalla

    // Forzar refresco de pantalla para ver la imagen
    lv_task_handler();

    // Espera activa por LOGO_DISPLAY_MS
    uint32_t start = lv_tick_get();
    while(lv_tick_elaps(start) < LOGO_DISPLAY_MS) {
        lv_task_handler();  // mantener animaciones y refresco activo
    }

    // Borrar la imagen para continuar con la UI normal
    lv_obj_del(logo_img_obj);
}