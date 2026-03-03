#include "logo.h"
#include "logo_frames.h"
#include "lvgl.h"

static lv_obj_t *logo_obj = NULL;
static uint8_t current_frame = 0;
static lv_timer_t *logo_timer = NULL;

/* ============================= */
/* Función que llama el timer    */
/* ============================= */
static void logo_timer_cb(lv_timer_t *timer)
{
    (void)timer; // evitar warning

    if (current_frame == 0)
    {
        lv_img_set_src(logo_obj, &logo_img1);
        current_frame = 1;
    }
    else
    {
        lv_img_set_src(logo_obj, &logo_img);
        current_frame = 0;
    }
}

/* ============================= */
/* Inicializa el logo            */
/* ============================= */
void logo_init(void)
{
    logo_obj = lv_img_create(lv_scr_act());
    lv_obj_align(logo_obj, LV_ALIGN_CENTER, 0, 0);

    // Mostrar primer frame
    lv_img_set_src(logo_obj, &logo_img);
    current_frame = 0;

    // Crear timer (200 ms entre frames)
    logo_timer = lv_timer_create(logo_timer_cb, 200, NULL);
}