#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <allegro.h>
#include "options.h"

using namespace std;

int Option::getDisplayMode()
{
     return this->displayMode;
}

void Option::setDisplayMode(int disp)
{
     this->displayMode = disp;
}

float Option::getAudioGain()
{
     return this->audioGain;
}

void Option::setAudioGain (float gain)
{
     this->audioGain = gain;
}
//fonctions
bool Option::changeDisplayMode(ALLEGRO_DISPLAY* display,int disp,ALLEGRO_DISPLAY_MODE disp_data)
{
     al_get_display_mode(disp, &disp_data);
     bool success = al_resize_display(display,disp_data.width, disp_data.height);
     return success;
}

void Option::changeAudioGain(float gain)
{
     this->audioGain = gain;

}

void Option::saveProfile(string name)
{
     string strinje = profile+".dat"; //ATTENTION ! LA MORT ! LA MORT
}
