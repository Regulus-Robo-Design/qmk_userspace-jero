#include "logo.h"
#include "logo_frames.c"  // Contiene la imagen m000_img

void logo_show_frame(void)
{
    // Crear el objeto de imagen
    lv_obj_t * img_obj = lv_img_create(lv_scr_act()); // pantalla activa
    lv_img_set_src(img_obj, &m000_img);              // asignar la imagen
    lv_obj_center(img_obj);                          // centrar

    // Mantener visible durante 2 segundos
    uint32_t start = lv_tick_get();
    while(lv_tick_elaps(start) < 2000) {
        lv_task_handler();  // refrescar pantalla LVGL
        lv_delay(5);        // pausa corta
    }

    // Borrar el logo de la pantalla
    lv_obj_del(img_obj);
}