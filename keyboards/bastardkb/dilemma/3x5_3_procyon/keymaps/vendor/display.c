#include "display.h"
#include "quantum.h"

lv_obj_t *ui_screen;
lv_obj_t *ui_label_layer_name;

enum ui_user_events {
    EVENT_LAYER_CHANGE = 0,
    EVENT_LAST_EVENT,
};

const char *ui_layer_strings[] = {"BASE", "FUNCTION", "NAV", "MED/RGB", "POINTER", "NUM", "SYM"};

void display_init(void) {

    // Screen stuff
    ui_screen = lv_obj_create(NULL);

    // // lv_obj_t *label = lv_label_create(ui_screen);
    // lv_label_set_text(label, "Hello world");
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // init layer indication
    ui_label_layer_name = lv_label_create(ui_screen);
    lv_label_set_text(ui_label_layer_name, "Base");
    lv_obj_add_event_cb(ui_label_layer_name, ui_layer_change, EVENT_LAYER_CHANGE, NULL);
    lv_obj_set_width(ui_label_layer_name, LV_SIZE_CONTENT);  /// 81
    lv_obj_set_height(ui_label_layer_name, LV_SIZE_CONTENT); /// 55
    lv_obj_set_x(ui_label_layer_name, 25);
    lv_obj_set_y(ui_label_layer_name, -10);
    lv_event_send(ui_label_layer_name, EVENT_LAYER_CHANGE, NULL);

    // Change the screen's background color
    lv_obj_set_style_bg_color(ui_screen, lv_color_hex(000000), LV_PART_MAIN);

    // set theme
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    lv_disp_load_scr(ui_screen);
    // end screen stuff

    prev_layer = 99;
}

void ui_layer_change(lv_event_t *e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == (uint8_t)EVENT_LAYER_CHANGE) {
        int layer = get_highest_layer(layer_state); // todo test that it's smaller than the max size (compare to size of layer_strings)
        lv_label_set_text(ui_label_layer_name, ui_layer_strings[layer]);
    }
}

void housekeeping_task_screen() {
    if (prev_layer != layer_state) {
        prev_layer   = layer_state;
        lv_event_send(ui_label_layer_name, EVENT_LAYER_CHANGE, NULL);
    }
}