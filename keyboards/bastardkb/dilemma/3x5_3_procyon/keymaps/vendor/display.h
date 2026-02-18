#include "lvgl.h"
#include QMK_KEYBOARD_H

extern lv_obj_t *ui_screen_base;
extern lv_obj_t *ui_label_layer_name;
extern lv_obj_t *ui_label_mod_gui;
extern lv_style_t style_btn;

void display_init(void);
void style_init_mod_indicator(void);

// void ui_layer_change(lv_event_t *e);
void ui_init_layer_name(lv_obj_t *label, const char* layer_name);
void housekeeping_task_screen(void);
void ui_init_mod_indicator(lv_obj_t *label, const char* indicator_name, int x, int y);
void event_screen_base_update_mods(void);

bool process_records_display(uint16_t keycode, keyrecord_t *record);

static uint8_t prev_layer;