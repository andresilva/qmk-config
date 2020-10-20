#include "layers.h"
#include "simple_visualizer.h"
#include "util.h"

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t layer = biton32(state->status.layer);

    lcd_backlight_brightness(255);

    switch (layer) {
    case MDIA:
        state->layer_text = "Media";

        state->target_lcd_color = LCD_COLOR(127, 255, 255);
        state->current_lcd_color = LCD_COLOR(127, 255, 255);
        state->prev_lcd_color = LCD_COLOR(127, 255, 255);

        break;
    case SYMB:
        state->layer_text = "Symbols";

        state->target_lcd_color = LCD_COLOR(64, 255, 255);
        state->current_lcd_color = LCD_COLOR(64, 255, 255);
        state->prev_lcd_color = LCD_COLOR(64, 255, 255);

        break;
    default:
        state->layer_text = "Base";

        state->target_lcd_color = LCD_COLOR(0, 0, 255);
        state->current_lcd_color = LCD_COLOR(0, 0, 255);
        state->prev_lcd_color = LCD_COLOR(0, 0, 255);

        break;
    }

    if ((state->status.mods & MOD_BIT(KC_LSFT))
        || (state->status.mods & MOD_BIT(KC_RSFT))
        || (state->status.leds & (1<<USB_LED_CAPS_LOCK))) {

        state->target_lcd_color = LCD_COLOR(212, 255, 255);
        state->current_lcd_color = LCD_COLOR(212, 255, 255);
        state->prev_lcd_color = LCD_COLOR(212, 255, 255);
    }
}
