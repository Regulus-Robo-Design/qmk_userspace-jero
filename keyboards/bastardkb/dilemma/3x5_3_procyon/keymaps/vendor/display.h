#include "lvgl.h"

extern lv_obj_t * ui_screen;
extern lv_obj_t * ui_layer_indicator;

void display_init(void);
void ui_layer_change(lv_event_t * e);
void housekeeping_task_screen(void);

static const char *ui_layer_strings[] = {"BASE", "FUNCTION", "NAV", "MED/RGB", "POINTER", "NUM", "SYM"};