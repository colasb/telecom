#include "film.h"
#include <iostream>
#include<string>

using namespace std;

Film::Film(): Video() {
    tabDuree = new int[0];
    nbChapitre = 0;
}

Film::Film(): Video() {
    this->nbChapitre = nbChapitre;
    tabDuree = new int[this->nbChapitre];
}

int * Film::getTabChap(){
    return * tabDuree;
}

int Film::getNbChaptre(){
    return nbChapitre;
}

void Film::setTabDuree(int *tab, int nbChapitre){
    this->tabDuree = tab;
    this->nbChapitre = nbChapitre;
}

void Film::affichage(ostream& ostream) const{
    ostream<<"Le film comporte "<<getNbChaptre()<<"."<<endl;
    for(int i=0;i<getNbChaptre();i++){
        ostream<<"Le chapitre "<<i+1<<" dure "<<getDuree()[i]<<" secondes."<<endl;
    }
}
