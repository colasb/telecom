#include "objetmultimedia.h"
#include <iostream>
#include<string>

using namespace std;


ObjetMultimedia::ObjetMultimedia(){
    name = "";
    pathname = "";
}
ObjetMultimedia::ObjetMultimedia(string nameObject, string pathnameObject){
    name = nameObject;
    pathname = pathnameObject;
}

void ObjetMultimedia::setName(string nameObject){
    name = nameObject;
}
void ObjetMultimedia::setPathname(string pathnameOject){
    pathname = pathnameOject;
}

string ObjetMultimedia::getName() const{
    return name;
}

string ObjetMultimedia::getPathname() const{
    return pathname;
}

void ObjetMultimedia::affichage(ostream& ostream) const{
    ostream <<"le nom de l'objet est "<<name<<endl;
    ostream<<"le chemin d'acces' de l'objet est "<<pathname<<endl;
}
ObjetMultimedia::~ObjetMultimedia(){

}
