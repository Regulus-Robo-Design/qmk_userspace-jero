VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
MAXTOUCH_DEBUG = no

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_DRIVERS += surface
ST7789 = true
SRC += gfx/fonts.qff.c
SRC += gfx/regular20.qff.c
SRC += gfx/regular20grey.qff.c
SRC += gfx/regular36.qff.c
SRC += gfx/semibold36.qff.c
SRC += gfx/jostmedium20.qff.c
SRC += gfx/jostmlight20.qff.c
SRC += gfx/jostmlight20grey.qff.c
SRC += gfx/jostbold36.qff.c
SRC += gfx/mods.qgf.c

BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = pwm