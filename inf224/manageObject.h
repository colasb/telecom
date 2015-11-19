#ifndef MANAGEOBJECT_H
#define MANAGEOBJECT_H

#include "groupe.h"
#include "video.h"
#include "film.h"
#include "photo.h"
#include "objetmultimedia.h"
#include <map>
#include <memory>

using namespace std;
typedef map<string, shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>>> Groupes;
typedef map<string, shared_ptr<ObjetMultimedia>> ObjetMultimedias;

class ManageObject {

private :
    ObjetMultimedias multimedias;
    Groupes groupes;
public :
     ManageObject(){}

    virtual shared_ptr<Photo> addPhoto(string name,string path, float latitude, float longitude)
     {shared_ptr<Photo> obj(new Photo(name,path, latitude, longitude)); multimedias[name] = obj; return obj;}

    virtual shared_ptr<Video> addVideo(string name,string path, int dureeVideo)
     {shared_ptr<Video> obj(new Video(name, path, dureeVideo)); multimedias[name] = obj; return obj;}

    virtual shared_ptr<Film> addFilm(int* tab, int nbChap, string nomVideo, string pathnameVideo, int dureeVideo)
     {shared_ptr<Film> obj(new Film(tab, nbChap, nomVideo, pathnameVideo, dureeVideo)); multimedias[nomVideo] = obj; return obj;}

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
        auto obj = multimedias.find(name);
        if(multimedias.find(name) == multimedias.end()){cout<<"This objet doesn't exist"<<endl;}
        else (*obj).second->getAttribut();

    }

 /*   virtual void searchGroup(string name, ostream & cout){
        auto groupe = groupes.find(name);
        if(groupes.find(name) == groupes.end()){cout<<"This group doesn't exist"<<endl;}
        else {(*groupe).second->affichage();}
    }*/

    virtual void playObject(string name){
        auto  obj= multimedias.find(name);
        if(multimedias.find(name) == multimedias.end()){cout<<"This objet doesn't exist"<<endl;}
        else (*obj).second->play();
    }

    virtual string getAttributObject(string name){
        auto obj = multimedias.find(name);
        if(multimedias.find(name) == multimedias.end())
            return name + "doesn't exist";
        else return (*obj).second->getAttribut();
    }


 /*   virtual string getAttributGroup(string name){
        auto groupe = groupes.find(name);
        if(groupes.find(name) == groupes.end())
            return "The group"+ name+ "doesn't exist";
        else (*groupe).second->getAttribut();
        }
 */

};

#endif // MANAGEOBJECT_H
