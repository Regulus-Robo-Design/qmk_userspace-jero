#include "logo.h"
#include "logo_frames.h"

static lv_obj_t *img = NULL;       // Objeto de imagen global
static lv_timer_t *logo_timer = NULL;  // Timer LVGL para borrar el logo

// Callback del temporizador: borra la imagen y elimina el timer
static void logo_timer_cb(lv_timer_t *timer) {
    if(img) {
        lv_obj_del(img);
        img = NULL;
    }
    lv_timer_del(timer);
}

// Función principal para mostrar el logo durante `ms` milisegundos
void logo_show_frame(uint32_t ms)
{
    if(img) return; // Evita reiniciar si ya hay logo en pantalla

    // Crear objeto imagen
    img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &logo_img);
    lv_obj_center(img);

    // Crear timer LVGL no bloqueante
    logo_timer = lv_timer_create(logo_timer_cb, ms, NULL);
}