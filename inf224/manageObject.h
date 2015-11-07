#ifndef MANAGEOBJECT_H
#define MANAGEOBJECT_H

#include "groupe.h"
#include "video.h"
#include "film.h"
#include "photo.h"
#include "objetmultimedia.h"
#include<map>
#include<memory>

using namespace std;
typedef map<string, shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>>> Groupes;
typedef map<string, shared_ptr<ObjetMultimedia>> ObjetMultimedias;

class ManageObject {

private :
    ObjetMultimedias multimedias;
    Groupes groupes;
public :
     ManageObject(){}

    virtual shared_ptr<Photo> addPhoto(string name,string path, float latitude, float longitude) {shared_ptr<Photo> obj(new Photo(name,path, latitude, longitude)); multimedias[name] = obj; return obj;}
    virtual shared_ptr<Video>  addVideo(string name,string path, int dureeVideo) {shared_ptr<Video> obj(new Video(name, path, dureeVideo)); multimedias[name] = obj; return obj;}
    virtual shared_ptr<Film>  addFilm(int* tab, int nbChap, string nomVideo, string pathnameVideo, int dureeVideo) {shared_ptr<Film> obj(new Film(tab, nbChap, nomVideo, pathnameVideo, dureeVideo)); multimedias[nomVideo] = obj; return obj;}
    virtual shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> addGroupe(string name)
     {shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> groupe(new Groupe<shared_ptr<ObjetMultimedia>>(name));
      groupes[name] = groupe; return groupe;}

    virtual void deleteGroupe(string name){ groupes.erase(name);}

    virtual void deleteMultimedia(string name){
        for(auto groupe : groupes){
            for(auto obj : *(groupe.second)){
                if((*obj).getName()==name) (*(groupe.second)).remove(obj);
            }
        }
        multimedias.erase(name);
    }

    virtual void searchObject(string name, ostream & cout){
        shared_ptr<ObjetMultimedia> obj = (*(multimedias.find(name))).second;
        if(obj) obj->affichage(cout);
        else cout<<"This objet doesn't exist"<<endl;

    }

    virtual void searchGroup(string name, ostream & cout){
        shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> groupe = (*(groupes.find(name))).second;
        if(groupe) {cout<<"6"<<endl;groupe->affichage(cout);}
        else {cout<<"This group doesn't exist"<<endl;}
    }

    virtual void playObject(string name){
        shared_ptr<ObjetMultimedia>  obj= (*(multimedias.find(name))).second;
        if(obj) obj->play();
        else cout<<"This objet doesn't exist"<<endl;

    }

    virtual void playGroup(string name){
        shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> groupe = (*(groupes.find(name))).second;
        if(groupe) groupe->play();
        else {cout<<"This group doesn't exist"<<endl;}
       }

};

#endif // MANAGEOBJECT_H
