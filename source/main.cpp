#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "options.h"
using namespace std;
float FPS = 60;

int main(int argc, char **argv)
    {

     ALLEGRO_TIMER * timer = NULL;
     bool redraw = true;
     ALLEGRO_DISPLAY *display = NULL;
     ALLEGRO_BITMAP  *image   = NULL;
     ALLEGRO_SAMPLE *son=NULL;
     int nbSon = 1;
     //création de la structure récéptacle des infos moniteurs
     ALLEGRO_DISPLAY_MODE disp_data;
     al_init();
     /*if(!al_init())
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
     */
     if(!al_init_image_addon())
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          return 0;
     }
//------------------------------------------------------------PARTIE SON-------------------------------------------------------------

     if(!al_install_audio())
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_install_audio!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
     }

     if(!al_init_acodec_addon()){
          fprintf(stderr, "failed to initialize audio codecs!\n");
          return -1;
     }

     if (!al_reserve_samples(nbSon)){ // le parametre est le nombre de sample a réserver
          fprintf(stderr, "failed to reserve samples!\n");
          return -1;
     }

     son = al_load_sample("kungfu.wav");


     //informations de la plus grande résolution suportée par le moniteur stockée dans la structure disp_data
     al_get_display_mode(0, &disp_data);

     //fullscreen flag on
     //al_set_new_display_flags(ALLEGRO_FULLSCREEN);

     //timer qui envoie un event à 1/fps secondes
     timer = al_create_timer(1.0 / FPS);
     if(!timer)
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
     }

     //on crée l'affichage avec la résolution max contenue dans disp_data
     display = al_create_display(disp_data.width, disp_data.height);
     if(!display)
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          al_destroy_timer(timer);
          return -1;
     }

    //pointeur sur la file d'events
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    //implémentation de l'event queue
    event_queue = al_create_event_queue();
    if(!event_queue) {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          al_destroy_display(display);
          return -1;
     }

     //on va enregistrer les events du display et du timer en plus de ceux par défauts
     al_register_event_source(event_queue, al_get_display_event_source(display));
     al_register_event_source(event_queue, al_get_timer_event_source(timer));

     al_clear_to_color(al_map_rgb(255,255,255));
     al_flip_display();
     al_start_timer(timer);




Option* opt= new Option();

//DEBUT
     //al_play_sample(son,1.0, 1.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);      <- BUG
     while(1)
     {
          ALLEGRO_EVENT ev;

          al_wait_for_event(event_queue, &ev ); //renvoie 1 si un event a eu lieu

          if (ev.type == ALLEGRO_EVENT_TIMER)
          {
               redraw = true;
          }
          else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
          {
               break;
          }

          if ((redraw ==true) && (al_is_event_queue_empty(event_queue)))
          {
               redraw=false;

               al_flip_display();
          };

     }
     al_destroy_timer(timer);
     al_destroy_display(display);
     al_destroy_event_queue(event_queue);
     return 0;
}
