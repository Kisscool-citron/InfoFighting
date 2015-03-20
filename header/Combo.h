#ifndef __INFOFIGHTING402v2__Combo__
#define __INFOFIGHTING402v2__Combo__

#include <stdio.h>
#include <allegro5/allegro.h>
#include <Coup.h>
#include <allegro5/keycodes.h>

class Combo
{
    private :
    /*Verifier le type ici présent merci . il est louche et on a pas de videur faudrais etre sur */

    Coup *tab[];
    int taille;

    public :

    Combo()
    {
        /*A VOIR COMMENT LES TOUCHE SONT GERER POUR REMPLIR UN TABLEAU DE COMBO PAR DEFAUT */
        tab[0]=new Coup();
        taille =1;
    }
    /*Ici le constructeur qui copie le tableau d'evenement dans l'instance actuel */
    Combo(Coup *t,int tailles)
    {
        tab[tailles];
        for(int i=0;i<tailles;i++)
        {
           tab[i]=&t[i];
        }
        this->taille=tailles;
    }
    /*COnstructeur par copie */
    Combo(const Combo &c)
    {
        taille=c.taille;
        for(int i = 0 ;i<taille; i++)
        {
            tab[i]=c.tab[i];
        }
    }
    /*Retourne le tableau de coup */
    Coup* get_tab()
    {
        return *tab;
    }
    /*set le tableau de coup */
    void set_tab(Coup* b,int a)
    {
        tab[a]=b;
    }
    /*Retourne la taille du tab de coup */
    int get_taille()
    {
        return taille;
    }
    /*set la taille du tableau de coup */
    void  set_taille(int a)
    {
        taille=a;
    }
    /*AFAIRE ! */
    int crer_combo();


};
#endif /* defined(__INFOFIGHTING402v2__Combo__) */
