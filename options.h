#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <string>
using namespace std;

class Options
{
     private:
          string profile;
          int DisplayMode;
          float AudioGain;
     public:
          Options();
          int getDisplayMode();
          void setDisplayMode(int);
          float getAudioGain();
          void setAudioGain(int);

          void changeDisplayMode(int);
          void changeAudioGain(float);
          void saveProfile(string);

};


#endif // OPTIONS_H_INCLUDED
