/*
 * AllegroDef.c
 *
 *  Created on: 07/06/2015
 *      Author: Bruno Pachceco & Felipe Sens Bonetto
 */

#include "AllegroDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


void initialization(){
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init_image_addon() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_install_keyboard()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_install_keyboard() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_init_primitives_addon()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init_primitives_addon() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_init_font_addon()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init_font_addon() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_init_ttf_addon()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init_ttf_addon() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_install_audio()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_install_audio() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	if (!al_init_acodec_addon()) {
		al_show_native_message_box(NULL, NULL, NULL,
								   "al_init_acodec_addon() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
}

