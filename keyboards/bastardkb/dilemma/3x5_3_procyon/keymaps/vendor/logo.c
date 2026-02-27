#include "logo.h"

static lv_obj_t *logo_label;

void logo_create(lv_obj_t *parent) {
    logo_label = lv_label_create(parent);
    lv_label_set_text(logo_label, "CURIO");
    lv_obj_align(logo_label, LV_ALIGN_BOTTOM_MID, 0, -10);
}

void logo_update(void) {
    // reservado para animaciones futuras
}