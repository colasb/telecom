#ifndef FILM_H
#define FILM_H
#include <iostream>
#include<string>
#include "video.h"

using namespace std;

class Film : public Video{
private:
        int* tabDuree;
        int nbChapitre;
public:
    Film();
    Film(int* tab, int nbChap, string nomVideo, string pathnameVideo, int dureeVideo);
    virtual void setTabDuree(int *tab, int nbChapitre);
    virtual int * getTabChap();
    virtual int getNbChaptre();
    virtual void affichage(ostream& ostream) const;
    virtual ~Film(){delete [] tabDuree;cout<<"The film "<<this->getName()<<" was delete"<<endl;}
};

#endif // FILM_H
