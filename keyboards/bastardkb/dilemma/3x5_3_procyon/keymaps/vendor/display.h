#include "lvgl.h"

extern lv_obj_t *ui_screen_base;
extern lv_obj_t *ui_label_layer_name;

void display_init(void);
void ui_layer_change(lv_event_t *e);
void housekeeping_task_screen(void);

static uint8_t prev_layer;