#ifndef GHOST_SQUID_H
#define GHOST_SQUID_H

#include "matrix.h"
#include "keymap_common.h"
#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif
#include <avr/io.h>
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, \
      k10,  k11   \
) \
{ \
    { k00, k01,   k02 }, \
    { k10, KC_NO, k11 }, \
}

void matrix_init_user(void);
void matrix_scan_user(void);
bool process_action_user(keyrecord_t *record);

/* LED pin configuration
 *
 * Scroll Lock  PB7
 * CAPS         PC6
 * NUMLOCK      PC5
 *
 */
void led_set(uint8_t usb_led)
{
    DDRB |= (1<<7);
    DDRC |= (1<<5) | (1<<6);

    if (usb_led & (1<<USB_LED_CAPS_LOCK))
    {
        PORTC &= ~(1<<6);
    }
    else
    {
        PORTC |= (1<<6);
    }

    if (usb_led & (1<<USB_LED_NUM_LOCK))
    {
        PORTC &= ~(1<<5);
    }
    else
    {
        PORTC |= (1<<5);
    }

    if (usb_led & (1<<USB_LED_SCROLL_LOCK))
    {
        PORTB &= ~(1<<7);
    }
    else
    {
        PORTB |= (1<<7);
    }
}

#endif
