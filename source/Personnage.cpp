#include "Personnage.h"
/*Methode qui fait que un personne prend les degat d'un coup via uen valeur entiere */
void Personnage::prendre_coup(int n)
{
    pv = pv-n;
}
    /*Methode qui retourne les pv  */
    int Personnage::get_pv()
    {
        return pv;
    }
    /*Methode qui retourne le nombre de combo effectue  */
    int Personnage::get_compteur()
    {
        return compteur_combo;
    }
    /*Methode qui retourne lle tableau des combo specifique a un perso  */
    int* Personnage::get_combo_speciaux()
    {
        return Combo_speciaux;
    }
    /*Methode qui retourne l'etat actuel du personnage  */
    int Personnage::get_etat()
    {
        return etat;
    }
    /*Methode qui modifie les pv  */
    void Personnage::set_pv(int n)
    {
        pv = n;
    }
    /*Methode qui modifie le compteur de combo   */
    void Personnage::set_compteur(int n)
    {
        compteur_combo=n;
    }
    /*Methode qui modifie le tableau de combo spéciaux par copie  */
    void Personnage::set_combo_speciaux(int * c,int taille)
    {
        for(int i = 0;i<taille;i++)
        {
            Combo_speciaux[i]=c[i];
        }
    }
    /*Methode qui modifie l'etat actuel du personnage   */
    void Personnage::set_etat(int n)
    {
        etat=n;
    }
