#include "logo.h"
#include "logo_frames.c" // Contiene el array del logo
#include "lvgl.h"        // Asegúrese de que lvgl esté incluido

void logo_show_frame(void) {
    lv_obj_t *img_obj = lv_img_create(lv_scr_act());
    lv_img_set_src(img_obj, &0000); // logo_img definido en logo_frames.c
    lv_obj_center(img_obj);

    lv_task_handler();  // Renderiza la pantalla una vez

    lv_timer_handler(); // Asegura que se refresque LVGL

    lv_tick_inc(2000);  // Opcional: simular 2 segundos de espera
    // Alternativamente, use un delay del sistema:
    lv_delay(2000);     // Esto depende de cómo esté configurado su LVGL
}