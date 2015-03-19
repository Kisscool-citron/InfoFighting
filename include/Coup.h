#ifndef COUP_H
#define COUP_H

#include <string>
#include <string.h>
#include <cstring>
using namespace std;
class Coup
{
    public:
        Coup();
        virtual ~Coup();
        Coup(const Coup& other);
        Coup& operator=(const Coup& other);
        /*Retourne le nom */
        string Getnom()
        {
            return nom;
        }
         /*etablie le nom */
        void Setnom(string val)
        {
            nom = val;
        }
         /*Retourne le nombre de frame*/
        int Getnb_frame()
        {
            return nb_frame;
        }
         /*etablie  le nombre de frame */
        void Setnb_frame(int val)
        {
            nb_frame = val;
        }
         /*Retourne l'etat de la garde */
        int Getgarde()
        {
            return garde;
        }
         /*etablie la garde */
        void Setgarde(int val)
        {
         garde = val;
        }
         /*Retourne le hit */
        int Gethit()
        {
            return hit;
         }
          /*etablie le hit*/
        void Sethit(int val)
        {
            hit = val;
        }
         /*Retourne le counter */
        int Getcounter()
        {
            return counter;
        }
        /*etablie le counter */
        void Setcounter(int val)
        {
            counter = val;
        }
         /*Retourne le degat du hit */
        int Getdegat_hit()
        {
            return degat_hit;
        }
        /*etablie le degat du hit */
        void Setdegat_hit(int val)
        {
            degat_hit = val;
        }
         /*Retourne ledegat du counter */
        int Getdegat_counter()
        {
            return degat_counter;
        }
        /*etablie le degat du counter */
        void Setdegat_counter(int val)
        {
            degat_counter = val;
        }
         /*Retourne le level */
        int Getlevel()
        {
            return level;
        }
        /*etablie le level */
        void Setlevel(int val)
        {
         level = val;
        }
         /*Retourne la manip*/
        int Getmanip()
        {
            return manip;
        }
         /*etablie la manip*/
        void Setmanip(int val)
        {
            manip = val;
        }
    protected:
    private:
        string nom;
        int nb_frame;
        int garde;
        int hit;
        int counter;
        int degat_hit;
        int degat_counter;
        int level;
        int manip;
};

#endif // COUP_H
