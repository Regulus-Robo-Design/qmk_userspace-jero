#include "display.h"
#include "quantum.h"

lv_obj_t *ui_screen_base;
lv_obj_t *ui_label_layer_name;

enum ui_user_events {
    EVENT_LAYER_CHANGE = 0,
    EVENT_LAST_EVENT,
};

const char *ui_layer_strings[] = {"BASE", "FUNCTION", "NAV", "MED/RGB", "POINTER", "NUM", "SYM"};

void display_init(void) {
    /*
        Base layer screen
    */
    ui_screen_base = lv_obj_create(NULL);
    ui_label_layer_name = lv_label_create(ui_screen_base);
    ui_init_layer_name(ui_label_layer_name, "Base");    
    // display base layer screen upon init
    lv_disp_load_scr(ui_screen_base);
    
    /*
        Theme
    */
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    prev_layer = 99;
}

void ui_init_layer_name(lv_obj_t *label, const char* layer_name){
    lv_label_set_text(label, layer_name);
    // lv_obj_set_width(label, LV_SIZE_CONTENT);
    // lv_obj_set_height(label, 30);
    lv_obj_set_x(label, 0);
    lv_obj_set_y(label, 0);
    lv_obj_set_align(label, LV_ALIGN_CENTER_MID);
}

void ui_init_mod_indicator(lv_obj_t *label, const char* indicator_name, int x, int y){
    lv_label_set_text(label, indicator_name);
    lv_obj_set_width(label, LV_SIZE_CONTENT);
    lv_obj_set_height(label, 30);
    lv_obj_set_x(label, x);
    lv_obj_set_y(label, y);
    lv_obj_set_align(label, LV_ALIGN_CENTER_MID);
}

// void ui_layer_change(lv_event_t *e) {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == (uint8_t)EVENT_LAYER_CHANGE) {
//         int layer = get_highest_layer(layer_state); // todo test that it's smaller than the max size (compare to size of layer_strings)
//         lv_label_set_text(ui_label_layer_name, ui_layer_strings[layer]);
//     }
// }

void housekeeping_task_screen() {
   
}