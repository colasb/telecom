#include "film.h"
#include <iostream>
#include<string>

using namespace std;

Film::Film(): Video() {
    tabDuree = new int[0];
    nbChapitre = 0;
}

Film::Film(int* tab, int nbChap, string nomVideo, string pathnameVideo, int dureeVideo): Video() {
    nbChapitre = nbChap;
    tabDuree = new int[nbChapitre];
    for(int i=0; i < this->nbChapitre; i++){tabDuree[i]= tab[i];}
}

int * Film::getTabChap(){
    return tabDuree;
}

int Film::getNbChaptre(){
    return nbChapitre;
}

void Film::setTabDuree(int *tab, int nbChapitre){
    tabDuree = new int[nbChapitre];
    this->nbChapitre = nbChapitre;
    for(int i=0; i < this->nbChapitre; i++){tabDuree[i]= tab[i];}
}

void Film::affichage(ostream& ostream) const{
    ostream<<"Le film comporte "<<nbChapitre<<"."<<endl;
    for(int i=0;i<nbChapitre;i++){
        ostream<<"Le chapitre "<<i+1<<" dure "<<tabDuree[i]<<" secondes."<<endl;
    }
}

string Film::getAttribut(){
    string s ="Le film comporte "+ to_string(nbChapitre) + ".";
    for(int i=0;i<nbChapitre;i++){
        s =+ " Le chapitre "+ to_string(i+1) + " dure "+ to_string(tabDuree[i]) +" secondes.";
    }
    return s;
}
