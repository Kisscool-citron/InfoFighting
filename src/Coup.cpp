#include "Coup.h"
/*Constructeur par défaut ici on initialise a des valeurs , a revoir */
Coup::Coup()
{
        nom="Le coup du démon";
        nb_frame=1;
        garde=0;
        hit=0;
        counter=0;
        degat_hit=1;
        degat_counter=0;
        level=1;
        manip=1;
}
/*Déstructeur*/
Coup::~Coup()
{
    //dtor
}
/*Constructeur par copie ici on initialise a des valeurs avec celle d'un autre coup , a revoir */
Coup::Coup(const Coup& other)
{
        nom=other.nom;
        nb_frame=other.nb_frame;
        garde=other.garde;
        hit=other.hit;
        counter=other.counter;
        degat_hit=other.degat_hit;
        degat_counter=other.degat_counter;
        level=other.level;
        manip=other.manip;
}
/*Operateur d'affectation */
Coup& Coup::operator=(const Coup& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
