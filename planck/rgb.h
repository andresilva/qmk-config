#include "lib/lib8tion/lib8tion.h"
#include "layers.h"

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

    switch (mode) {
    case 1: { // breathing
        uint16_t time = scale16by8(g_rgb_timer, speed / 8);
        hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
        RGB rgb = hsv_to_rgb(hsv);
        for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        break;
    }
    default: { // solid
        RGB rgb = hsv_to_rgb(hsv);
        for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        break;
    }
    }
}

void rgb_matrix_indicators_kb(void) {
    switch (get_highest_layer(layer_state)) {
    case SYMB:
        rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
        break;
    case NUM:
        rgb_matrix_layer_helper(HSV_ORANGE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
        break;
    case FN:
        rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
        break;
    case NAV:
        rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
        break;
    default:
        rgb_matrix_layer_helper(HSV_WHITE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
        break;
    }
}
