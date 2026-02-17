#include "display.h"
#include "quantum.h"

lv_obj_t *ui_screen;
lv_obj_t *ui_layer_indicator;

enum ui_user_events {
    EVENT_LAYER_CHANGE = 0,
    EVENT_LAST_EVENT,
};

void display_init(void) {
    ui_screen = lv_obj_create(NULL);

    // // lv_obj_t *label = lv_label_create(ui_screen);
    // lv_label_set_text(label, "Hello world");
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // init layer indication
    ui_layer_indicator = lv_label_create(ui_screen);
    lv_label_set_text(ui_layer_indicator, "Hello world");
    lv_obj_align(ui_layer_indicator, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(ui_layer_indicator, ui_layer_change, EVENT_LAYER_CHANGE, NULL);
    lv_obj_set_width(ui_layer_indicator, LV_SIZE_CONTENT);  /// 81
    lv_obj_set_height(ui_layer_indicator, LV_SIZE_CONTENT); /// 55
    lv_obj_set_x(ui_layer_indicator, 25);
    lv_obj_set_y(ui_layer_indicator, -10);
    lv_obj_set_align(ui_layer_indicator, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_layer_indicator, LV_OBJ_FLAG_ADV_HITTEST); /// Flags
    lv_obj_clear_flag(ui_layer_indicator, LV_OBJ_FLAG_SCROLLABLE);
    lv_event_send(ui_layer_indicator, EVENT_LAYER_CHANGE, NULL);

    lv_disp_load_scr(ui_screen);
}

void ui_layer_change(lv_event_t *e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == EVENT_LAYER_CHANGE) {
        lv_label_set_text(ui_layer_indicator, bk_layer_str(get_highest_layer(layer_state)));
    }
}

void housekeeping_task_screen() {}