//MainMenu
int draw_bouton(BITMAP *buffer, int posx, int posy, int pos2x, int pos2y, int color1, int color2, int profondeur, char* texte)
    {
    int pos_mouse=1; // Pour savoir si la souris est sur le bouton
    int color; // Pour definir la couleur du bouton
    int c_hg; // Couleur du coin haut gauche
    int c_bd; // Couleur du coin bas droite
    int texte_x; // Position du texte en x
    int texte_y; // Position du texte en y
    int retour=0; // Renvoi
    int i;

    if(profondeur >5)profondeur=5;
    if(profondeur <=0)profondeur=1;

    // Si la souris est sur le bouton on modifie la valeur de pos_mouse
    if(mouse_x>=posx && mouse_x<=pos2x && mouse_y>=posy && mouse_y<=pos2y)
        {
        pos_mouse=2;
        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
            {
            pos_mouse=3;
            // On renvoie un 1 si le bouton est enfoncé
            retour=1;
            }
        }
    else pos_mouse=1;

    // Changement des couleurs pour les effets de perspective et pour savoir si la souris est sur le bouton
    switch(pos_mouse)
        {
        case 1:c_hg=255;c_bd=0;
               color=color1;
               texte_x=(posx+pos2x)/2;
               texte_y=(posy+pos2y)/2;
               break;
        case 2:c_hg=255;c_bd=0;
               color=color2;
               texte_x=(posx+pos2x)/2;
               texte_y=(posy+pos2y)/2;
               break;
        case 3:c_hg=0;c_bd=255;
               color=color2;
               texte_x=((posx+pos2x)/2)+profondeur;
               texte_y=((posy+pos2y)/2)+profondeur;
               break;
        }

    // Dessin de lignes blanches et noires pour la perspective
    for(i=0;i!=profondeur;i++)
        {
        hline(buffer,posx,posy+i,pos2x-i,makecol(c_hg,c_hg,c_hg));
        vline(buffer,posx+i,posy,pos2y-i,makecol(c_hg,c_hg,c_hg));
        hline(buffer,posx+i,pos2y-i,pos2x,makecol(c_bd,c_bd,c_bd));
        vline(buffer,pos2x-i,posy+i,pos2y,makecol(c_bd,c_bd,c_bd));
        }

    // Remplissage du bouton
    rectfill(buffer,posx+profondeur,posy+profondeur,pos2x-profondeur,pos2y-profondeur,color);
    // Ecriture du texte
    textprintf_centre(buffer,font,texte_x,texte_y,makecol(255,255,255),"%s",texte);

    // Renvoi : 1 si le bouton a été cliqué, 0 sinon
    return retour;
    }
class CState1 : public IState
{
     void Init()
     {
          /*Charger 'image de fond du menu
            Lancer musique
            crer des buttons BOX area clickable
           */
            /*FOND DU MENU */
           ALLEGRO_BITMAP* image_fond = new ALLEGRO_BITMAP;
           image_fond=al_load_bitmap("images/image_fond.bmp");
            /*VOIR UNE FUCKING LIBRAIRIE */

            /* BOUTON */
            ALLEGRO_BITMAP* menu1 = new ALLEGRO_BITMAP;
             menu1=al_load_bitmap("images/menu1.bmp");
             ALLEGRO_BITMAP* menu1 = new ALLEGRO_BITMAP;
             menu2=al_load_bitmap("images/menu2.bmp");
             ALLEGRO_BITMAP* menu1 = new ALLEGRO_BITMAP;
             menu3=al_load_bitmap("images/menu3.bmp");

            draw_bouton(menu1 int posx, int posy, int pos2x, int pos2y, int color1, int color2, int profondeur, "Jeu");
            draw_bouton(menu2, int posx, int posy, int pos2x, int pos2y, int color1, int color2, int profondeur, "Options")
            draw_bouton(menu3, int posx, int posy, int pos2x, int pos2y, int color1, int color2, int profondeur, "Quitter")

             }

     EState Process()
     {
    /*Detection sur un click sur un button
        traitements vers les menus cliqués*/
     }
     void Clean()
     {
        /*DELETE TOUT CA

            -Charger 'image de fond du menu
            -crer des buttons BOX area clickable
           */
     }
}
//OptionMenu
class CState2 : public IState
{
     void Init()
     {
        /*
        image de fond du menu otpions
        cases pour modifier valeurs
        */
     }
     EState Process()
     {
        /*
            si cases modifiées appel des fonctions
        */
     }
     void Clean()
     {
        /*
            nettoyage du fond et cases
        */
     }
}
//Fight
class CState3 : public IState
{
     void Init()
     {
        /*
            nettoyage de la zic
            lancement de la zic fight
            chargement image fond
            créations items
                persos
                hitboxes de base
                combos
        */
     }
     EState Process()
     {

     }
     void Clean()
     {
        /*
            tout nettoyer
        */
     }
}
