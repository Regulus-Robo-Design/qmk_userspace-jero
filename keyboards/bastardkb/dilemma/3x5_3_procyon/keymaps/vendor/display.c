#include "display.h"
#include "quantum.h"

lv_obj_t * ui_screen;

void display_init(void){

    ui_screen      = lv_obj_create(NULL);
    lv_obj_t *label = lv_label_create(ui_screen);
    lv_label_set_text(label, "Hello world");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_disp_load_scr(ui_screen); 
}

void housekeeping_task_screen(){

}