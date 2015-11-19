#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include<string>
#include "objetmultimedia.h"


using namespace std;

class Video : public ObjetMultimedia
{
    int duree;
public:
    Video(): ObjetMultimedia(){duree = 0;}
    Video(string nomVideo, string pathnameVideo, int dureeVideo): ObjetMultimedia(nomVideo, pathnameVideo){duree = dureeVideo;}
    virtual int getDuree() const{ return duree; }  
    virtual void setDuree(int dureeVideo){duree = dureeVideo;}

    virtual void affichage(ostream& ostream) const{
        ostream<<"le nom de la video est "<<getName()<<endl;
        ostream<<"le chemin d'acces' de la video est "<<getPathname()<<endl;
        ostream<<"la duree de la video est de "<<duree<<" secondes"<<endl;
    }

    virtual string getAttribut(){
        return "le nom de la video est " + getName() +
        ", le chemin d'acces' de la video est " + getPathname() +
        ", la duree de la video est de " + to_string(duree) +" secondes.";
    }


    virtual void play() const{system(("mpv " + getPathname() + "&").c_str()); }
    virtual ~Video(){cout<<"The video "<<this->getName()<<" was delete"<<endl;}
};

#endif // VIDEO_H
