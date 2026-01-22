// painter_font_handle_t font_layer;
// painter_font_handle_t font_menu;
// painter_font_handle_t font_menu_off;
static uint8_t prev_layer;

// #undef RP_PWM_USE_PWM2
#define RP_PWM_USE_PWM2 TRUE
#undef HAL_USE_PWM
#define HAL_USE_PWM TRUE

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE


// void bk_display_layer_number(void);
// void bk_render_mods(uint16_t x, uint16_t y,bool render_all); 
// const char *layer_str(dilemma_keymap_layers layer);
// const hsv_t  (dilemma_keymap_layers layer);

// static const char *layer_strings[] = {
//     [LAYER_BASE]       = "00 BASE",
//     [LAYER_FUNCTION]   = "01 FUNCT",
//     [LAYER_NAVIGATION] = "02 NAV",
//     [LAYER_MEDIA]      = "03 MED/RGB",
//     [LAYER_POINTER]    = "04 POINT",
//     [LAYER_NUMERAL]    = "05 NUM",
//     [LAYER_SYMBOLS]    = "06 SYM"
// }; 

// static const hsv_t colors[] = {
//     [LAYER_BASE]       = {HSV_WHITE},
//     [LAYER_FUNCTION]   = {HSV_BLUE},
//     [LAYER_NAVIGATION] = {HSV_AZURE},
//     [LAYER_MEDIA]      = {HSV_ORANGE},
//     [LAYER_POINTER]    = {HSV_GREEN},
//     [LAYER_NUMERAL]    = {HSV_TEAL},
//     [LAYER_SYMBOLS]    = {HSV_PURPLE}
// };