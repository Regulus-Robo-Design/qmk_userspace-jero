#include "logo.h"
#include "logo_frames.c"

void logo_show_frame(void)
{
    lv_obj_t *img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &logo_img);
    lv_obj_center(img);

    lv_timer_handler();

    uint32_t start = lv_tick_get();
    while(lv_tick_elaps(start) < 2000)
    {
        lv_timer_handler();
    }

    lv_obj_del(img);
}