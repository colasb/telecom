#include"objetmultimedia.h"
#include"photo.h"
#include"video.h"
#include <iostream>
#include<string>
#include<list>
#include <unistd.h>
#include"film.h"

using namespace std;

int main(void){
    list<ObjetMultimedia*> listObjet;
    listObjet.push_back(new Photo("hiver", "hiver.jpeg", 12.0, 14.0));
    listObjet.push_back(new Photo("hiver", "hivr.jpeg", 13.0, 16.0));
    listObjet.push_back(new Photo("hiver", "hver.jpeg", 12.0, 17.0));
    listObjet.push_back(new Photo("hiver", "hive.jpeg", 11.0, 19.0));
    listObjet.push_back(new Video("tab4", "vio.mp4", 5));
    listObjet.push_back(new Video("tab4", "video.mp4", 58));
    listObjet.push_back(new Video("tab4", "vid.mp4", 57));
    listObjet.push_back(new Video("tab4", "vdeo.mp4", 5));
    listObjet.push_back(new Video("tab4", "vo.mp4", 5));


    for (auto object : listObjet) object->affichage(cout);

    Video* obj = new Video("tab4", "vid.mp4", 57);
    obj->affichage(cout);
    obj->play();
    usleep(5000000);


    Photo * pho =new Photo("hiver", "hiver.jpg", 12.0, 14.0);
    pho->play();
    usleep(5000000);
    pho->affichage(cout);   
    int tab[5]= {1,1,85,65,4};
    int a =5;
    int b =156;
    string c="super";
    string d= "path";
    Film * film = new Film(tab,a,c,d,b);
    film->affichage(cout);
    return 0;

}



