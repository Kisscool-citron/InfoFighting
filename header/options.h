#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <string>
using namespace std;

class Option
{
     private:
          //int numero; ?
          string profile;
          int displayMode;
          float audioGain;
     public:
          //constructeurs
          Option()
          {
               displayMode = 0;
               profile = "defaut";
               float audioGain = 1.0;
          }
          Option(string profile, int disp, float audio)
          {
               this->displayMode = disp;
               this->profile = profile;
               this->audioGain = audio;
          }
          //getters setters
          int getDisplayMode();
          void setDisplayMode(int);
          float getAudioGain();
          void setAudioGain(float);

          //fonctions
          bool changeDisplayMode(ALLEGRO_DISPLAY*,int,ALLEGRO_DISPLAY_MODE);
          void changeAudioGain(float);
          void saveProfile(string);
};


#endif // OPTIONS_H_INCLUDED
