#include "logo.h"
#include "logo_frames.h"
#include "lvgl.h"

static lv_obj_t *logo_obj = NULL;
static uint8_t current_frame = 0;

/* ============================= */
/* Inicializa el logo en pantalla */
/* ============================= */
void logo_init(void)
{
    logo_obj = lv_img_create(lv_scr_act());
    lv_obj_align(logo_obj, LV_ALIGN_CENTER, 0, 0);

    // Mostrar el primer frame
    lv_img_set_src(logo_obj, &logo_img);
    current_frame = 0;
}

/* ============================= */
/* Cambia al siguiente frame     */
/* ============================= */
void logo_next_frame(void)
{
    if (logo_obj == NULL) return;

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