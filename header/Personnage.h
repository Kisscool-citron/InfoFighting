#ifndef __INFOFIGHTING402v2__Personnage__
#define __INFOFIGHTING402v2__Personnage__

#include <stdio.h>
#include <allegro5/allegro.h>

class Personnage{

    int pv ;
    int* Combo_speciaux;
    int compteur_combo;
    int taille;
    int etat ; /*Etat 1 : sur le ground , etat 2 en l'air , etat 3 accroupie , etat 4 en combo */
    /*PENSER A UNE FUCKING HITBOXE*/
    Personnage()
    {
        pv = 100;
        compteur_combo=0;
        taille =0;
        etat =1;
    }
    /*Construction du personange par initialisation des parametre*/
    Personnage(int p,int c ,int *tab,int taille,int et)
    {
        pv=p;
        compteur_combo=c;
        Combo_speciaux= tab;
        this->taille=taille;
        etat=et;
    }
    /*Constructuer par copie */
    Personnage(const Personnage &p)
    {
        pv=p.pv;
        compteur_combo=p.compteur_combo;

        Combo_speciaux= new int[p.taille];
        for(int i =0;i<p.taille;i++)
        {
           Combo_speciaux[i]= p.Combo_speciaux[i];
        }
        etat=p.etat;
    }
    /*FONCTION EXPLIQUER EN POINT H*/
    void prendre_coup(int n);
    int get_pv();
    int get_compteur();
    int* get_combo_speciaux();
    int get_etat();

    void set_pv(int n);
    void set_compteur(int n);
    void set_combo_speciaux(int * c,int taille);
    void set_etat(int n);
};

#endif /* defined(__INFOFIGHTING402v2__Personnage__) */
