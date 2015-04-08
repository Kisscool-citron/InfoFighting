#ifndef PERSONNAGE_JOUABLE_H
#define PERSONNAGE_JOUABLE_H

#include <Personnage.h>
#include <string.h>

class Personnage_jouable : public Personnage
{
    public:
        /*Constructuer par défaut de Personnage jouable qui hérite
         de personnage en lui donnant un nom , beau geste familliale */
        Personnage_jouable()
        {
            nom ="ryu";
        }
        /*Destructeur de personnage*/
        virtual ~Personnage_jouable();
        /*Constructeur par copie d'un autre joueur personnage_jouable*/
        Personnage_jouable(const Personnage_jouable& autre)
        {
            nom=autre.nom;
        }
        Personnage_jouable(int choix);
        /*Retourne le nom du personnage*/
        String Get()
        {
        return nom;
        }
        /*Etablie le nom du personnage*/
        void Set(String val)
        {
         nom = val;
        }
    protected:

    private:
        String nom;
};

#endif // PERSONNAGE_JOUABLE_H
