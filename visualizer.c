#include <string.h>
#include "layers.h"
#include "simple_visualizer.h"
#include "util.h"

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    static char text[20];
    uint32_t color;
    uint8_t layer = biton32(state->status.layer);

    memset(text, 0, sizeof(text));

    switch (layer) {
    case MDIA:
        strcat(text, "Media");
        color = LCD_COLOR(127, 255, 255);
        break;
    case SYMB:
        strcat(text, "Symbols");
        color = LCD_COLOR(64, 255, 255);
        break;
    default:
        strcat(text, "Base");
        color = LCD_COLOR(0, 0, 255);
        break;
    }

    if ((state->status.mods & MOD_BIT(KC_LSFT))
        || (state->status.mods & MOD_BIT(KC_RSFT))
        || (state->status.leds & (1<<USB_LED_CAPS_LOCK)))
    {
        strcat(text, " [SFT]");
        color = LCD_COLOR(212, 255, 255);
    }

    // set all color fields so that the color change is immediate
    // without any transition applied.
    state->target_lcd_color = color;
    state->current_lcd_color = color;
    state->prev_lcd_color = color;

    state->layer_text = text;

    lcd_backlight_brightness(255);
}
