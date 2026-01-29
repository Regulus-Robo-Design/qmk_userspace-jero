painter_font_handle_t bk_font_layer;
painter_font_handle_t bk_font_menu;
painter_font_handle_t bk_font_menu_off;
static uint8_t        prev_layer;
static uint8_t        last_mods;

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

const char *bk_layer_str(enum dilemma_keymap_layers layer);
void        bk_display_layer_name(int x, int y, int layer, painter_font_handle_t font);
int         bk_display_layer_info(int x, int y, int layer, painter_font_handle_t font, bool rewrite_all);

int bk_layer_base_mods(uint16_t x, uint16_t y, painter_font_handle_t font_on, painter_font_handle_t font_off, bool render_all);
// const char *layer_str(dilemma_keymap_layers layer);
const hsv_t bk_layer_color(enum dilemma_keymap_layers layer);
bool        bk_mods_have_changed(void);

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