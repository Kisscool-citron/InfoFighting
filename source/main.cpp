#include "../header/Initialisation.h"
#include "../header/options.h"
#include "../header/Coup.h"
#include "../header/Jeu.h"

using namespace std;

int main(int argc, char **argv)
    {

     bool redraw = true;
     ALLEGRO_DISPLAY *display = NULL;
     ALLEGRO_BITMAP  *image   = NULL;
     ALLEGRO_SAMPLE *son=NULL;
     int nbSon = 1;
     //création de la structure récéptacle des infos moniteurs
     ALLEGRO_DISPLAY_MODE disp_data;
     if(!al_init())
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
     }
     if(!al_init_image_addon())
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          return 0;
     }
/*------------------------------------------------------------PARTIE SON-------------------------------------------------------------*/

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

/*---------------------------------------------------FIN PARTIE SON-----------------------------------------------*/

     //informations de la plus grande résolution suportée par le moniteur stockée dans la structure disp_data
     al_get_display_mode(0, &disp_data);

     //fullscreen flag on
     //al_set_new_display_flags(ALLEGRO_FULLSCREEN);


     //on crée l'affichage avec la résolution max contenue dans disp_data
     display = al_create_display(disp_data.width, disp_data.height);
     if(!display)
     {
          al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
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


     Option* opt= new Option();

     //DEBUT
     //al_play_sample(son,1.0, 1.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);      <- BUG
     const float UPDATES_PER_SECOND = 20.0f;
     const float FRAMES_PER_SECOND = 60.0f;
     ALLEGRO_TIMER* update_timer = al_create_timer(1/UPDATES_PER_SECOND);
     ALLEGRO_TIMER* display_timer = al_create_timer(1/FRAMES_PER_SECOND);
	al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)update_timer);
     al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)display_timer);
     al_start_timer(update_timer);
     al_start_timer(display_timer);

     bool running = true;
     /*---------------------------STATES------------------------------*/
     //numération des states pour le tableau de states
     enum EState
     {
          e_StateMainMenu,
          e_StateOptionMenu,
          e_StateFight,
          e_NbState,

     };
     //tableau des states
     IState* states [e_NbState] =
     {
          new CState1,
          new CState2,
          new CState3,
     }

     EState eCurrent = e_StateMainMenu; //on se positionne sur le premier state
     EState next = e_StateMainMenu;
     /*-----------------------INITIALISATION-------------------------*/
     ALLEGRO_BITMAP** ABitMapTab = new ALLEGRO_BITMAP*[3];

     Coup* A = new Coup(19,-4,2,2,12,14,1, ALLEGRO_KEY_A, ABitMapTab, 3);
     ABitMapTab[0] = al_load_bitmap("images/A1.bmp");
     ABitMapTab[1] = al_load_bitmap("images/A2.bmp");
     ABitMapTab[2] = al_load_bitmap("images/A1.bmp");
     bool isLogicUpdateNeeded = true;
     bool isDisplayUpdateNeeded = true;
     int i = 0;


     ALLEGRO_BITMAP* image2;
     image = al_load_bitmap("images/bb_1.png");
     image2 = al_load_bitmap("images/bb_1.bmp");

     states[eCurrent].Init(); // premiere init
          while(running)
     {

          while(!al_is_event_queue_empty(event_queue)){
               ALLEGRO_EVENT e;
               al_wait_for_event(event_queue, &e);
               switch(e.type)
               {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                    break;

                    case ALLEGRO_EVENT_TIMER:
                    if(e.timer.source == update_timer)
                    {

                         isLogicUpdateNeeded = true;
                    }
                    else if(e.timer.source == display_timer)
                    {
                         isDisplayUpdateNeeded = true;
                    }
                    break;
               }
               if(isLogicUpdateNeeded)
               {
                    if(eCurrent != eNext)
                    {
                         //nettoyage du dernier state
                         states[eCurrent].Clean();
                         //init du next state
                         states[eNext].Init();
                         //actualisation des states
                         eCurrent = eNext;
                    }
                    isLogicUpdateNeeded = false;
                    al_draw_bitmap(image,0,0,NULL);

                    //updateLogic();
               }
               if(isDisplayUpdateNeeded)
               {
                    isDisplayUpdateNeeded = false;
                    al_flip_display(); //updateDisplay();

               }
          }

     }
     al_destroy_bitmap(image);
     al_destroy_display(display);
     al_destroy_event_queue(event_queue);
     al_destroy_timer(update_timer);
     al_destroy_timer(display_timer);
     return 0;
}
