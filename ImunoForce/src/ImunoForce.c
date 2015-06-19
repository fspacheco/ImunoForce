#include <stdio.h>
#include "ImunoEngine.h"
#include "AllegroDef.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

//Object object_head = {0,header,NULL,NULL,NULL,NULL};


int main(int argc, char *argv[])
{
	int frame=1, bTrig=10, bulletFreq=10, i;
	int currentPlayer = 1; // JUST FOR TEST

	ALLEGRO_DISPLAY*			display;
	ALLEGRO_TIMER*				timer;
	ALLEGRO_EVENT				ev;
	ALLEGRO_EVENT_QUEUE*		event_queue;
	bool quit = false;

	Object* p = object_search(header);
	Object* bllt = object_search(header);

	initialization();

	//creation(display, timer, event_queue);
	display = al_create_display(DISPLAY_W, DISPLAY_H);
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL,
			"al_create_display() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	timer = al_create_timer(1 / 60.0);
	if (!timer) {
		al_show_native_message_box(NULL, NULL, NULL,
			"al_create_timer() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(NULL, NULL, NULL,
			"al_create_event_queue() failed", NULL, 0);
		exit(EXIT_FAILURE);
	}

	Mask *b = mask_new(al_load_bitmap("Sprites/sperm_0S.png"));
	ALLEGRO_BITMAP* p_sprites[12];
	p_sprites[0] = al_load_bitmap("Sprites/sperm_0M.png");
	p_sprites[1] = al_load_bitmap("Sprites/sperm_1M.png");
	p_sprites[2] = al_load_bitmap("Sprites/sperm_2M.png");
	p_sprites[3] = al_load_bitmap("Sprites/sperm_3M.png");
	p_sprites[4] = al_load_bitmap("Sprites/sperm_4M.png");
	p_sprites[5] = al_load_bitmap("Sprites/sperm_5M.png");
	p_sprites[6] = al_load_bitmap("Sprites/sperm_6M.png");
	p_sprites[7] = al_load_bitmap("Sprites/sperm_7M.png");
	p_sprites[8] = al_load_bitmap("Sprites/sperm_8M.png");
	p_sprites[9] = al_load_bitmap("Sprites/sperm_9M.png");
	p_sprites[10] = al_load_bitmap("Sprites/sperm_10M.png");
	p_sprites[11] = al_load_bitmap("Sprites/sperm_11M.png");

	Mask *p_masks[12];
	for (i = 0; i < 12; i++) {
		p_masks[i] = mask_new(p_sprites[i]);
		printf("Creating mask n%d\n",i+1);
	}



	//initializes 2 players
	p = player_add(p, "Sprites/sperm_0M.png");
	//player_add(p,"Sprites/sperm_0L.png");
	p = object_search(1);

    Object normal;
        normal.img = al_load_bitmap("Sprites/sperm_0S.png");
		normal.img_i = 0;
        normal.mask = mask_new(normal.img);
        normal.height = al_get_bitmap_height(normal.img);
        normal.width = al_get_bitmap_width(normal.img);
        normal.vx = 0;
        normal.vy = 0;

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!quit) {
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				quit = true;
			}

			if (ev.type == ALLEGRO_EVENT_TIMER) {
				//	FRAME COUNT
				frame = (frame >= 60) ? 1 : frame + 1;


				p = object_search(currentPlayer);

				// ANIMATION


				
				//	MOVEMENT
				//move_player(player);
								
				p->y += 0.5*keys[KEY_DOWN] - 0.5*keys[KEY_UP];
				p->x += 0.5*keys[KEY_RIGHT] - 0.5*keys[KEY_LEFT];


				//	FIRE
				//fire_bullet(player);
				if (keys[KEY_SPACE] && bTrig == 10) {

					bullet_add(normal,currentPlayer);
					bTrig = frame % bulletFreq;
				}
				else if (keys[KEY_SPACE] && frame%bulletFreq == bTrig) {
					bullet_add(normal,currentPlayer);
				}
				else if (!keys[KEY_SPACE]) {
					bTrig = 10;
				}
				anim(p, 5, p_sprites, p_masks, 12);
				object_colision();
				object_move();
				object_draw();
			}

			//	KEYBOARD VERIFICATION
			//keyboard_verification(ev);
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					keys[KEY_UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[KEY_DOWN] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[KEY_LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[KEY_RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[KEY_SPACE] = true;
					break;
				case ALLEGRO_KEY_1:
					keys[KEY_1] = true;
					break;
				case ALLEGRO_KEY_2:
					keys[KEY_2] = true;
					break;
				}
			}
			if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					keys[KEY_UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[KEY_DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[KEY_LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[KEY_RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[KEY_SPACE] = false;
					break;
				case ALLEGRO_KEY_1:
					keys[KEY_1] = false;
					break;
				case ALLEGRO_KEY_2:
					keys[KEY_2] = false;
					break;
				}
			}

			if( al_is_event_queue_empty(event_queue)){


				object_draw();
				//object_track();

				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}

		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		al_destroy_bitmap(p->img);

		exit(EXIT_SUCCESS);
}
