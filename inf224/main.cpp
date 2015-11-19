#include"objetmultimedia.h"
#include"photo.h"
#include"video.h"
#include <iostream>
#include<string>
#include<list>
#include <unistd.h>
#include"film.h"
#include"groupe.h"
#include <memory>
#include"manageObject.h"
#include "TCPServer.h"
#include "server.h"

typedef Groupe<shared_ptr<ObjetMultimedia>> T;

using namespace std;

int 
main(int argc, char* argv[]){
    /*list<ObjetMultimedia*> listObjet;
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
    film->affichage(cout);*/

    /*shared_ptr<T> groupPhoto (new Groupe<shared_ptr<ObjetMultimedia>>("Photal"));
    shared_ptr<T> groupFilm (new Groupe<shared_ptr<ObjetMultimedia>>("Nanare"));
    shared_ptr<T> mixte (new Groupe<shared_ptr<ObjetMultimedia>>("Mes vacances"));

    shared_ptr<ObjetMultimedia> clicher1 (new Photo("hiver", "hver.jpeg", 12.06, 17.50));
    shared_ptr<ObjetMultimedia> clicher2 (new Photo("hiver", "hive.jpeg", 11.011, 19.10));
    shared_ptr<ObjetMultimedia> film1 (new Video("t4", "vdeo.mp4", 57));
    shared_ptr<ObjetMultimedia> film2 (new Video("t9ab4", "vo.mp4", 75));

    groupPhoto->push_back(shared_ptr<ObjetMultimedia>(new Photo("hiver", "hiver.jpeg", 12.10, 14.770)));
    groupPhoto->push_back(shared_ptr<ObjetMultimedia>(new Photo("hiver", "hivr.jpeg", 13.30, 16.50)));
    groupPhoto->push_back(clicher1);
    groupPhoto->push_back(clicher2);

    groupFilm->push_back(shared_ptr<ObjetMultimedia>(new Video("tab4", "vio.mp4", 508)));
    groupFilm->push_back(shared_ptr<ObjetMultimedia>(new Video("tab5", "video.mp4",158)));
    groupFilm->push_back(shared_ptr<ObjetMultimedia>(new Video("ta7", "vid.mp4", 571)));
    groupFilm->push_back(shared_ptr<ObjetMultimedia>(new Video("t4", "vdeo.mp4", 57)));
    groupFilm->push_back(shared_ptr<ObjetMultimedia>(new Video("t9ab4", "vo.mp4", 75)));
    groupPhoto->push_back(film2);

    groupPhoto->push_back(film1);
    mixte->push_back(clicher1);
    mixte->push_back(clicher2);
    mixte->push_back(film1);
    mixte->push_back(film2);
    mixte->affichage(cout);
    groupFilm->affichage(cout);
    groupPhoto->affichage(cout);*/

 /*   int tab[5]= {1,1,85,65,4};
    int a =5;
    int b =156;
    string c="super";
    string d= "path";*/

    ManageObject* mo = new ManageObject();
    shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> groupPhoto = mo->addGroupe("Groupe Photal");
    shared_ptr<Groupe<shared_ptr<ObjetMultimedia>>> groupFilm = mo->addGroupe("Groupe Film");
    shared_ptr<Photo> photo = mo->addPhoto("hiver", "hiver.jpeg", 13.30, 16.50);
    shared_ptr<Video> video = mo->addVideo("t9ab4", "vo.mp4", 75);
  //  shared_ptr<Film> film = mo->addFilm(tab,a,c,d,b);

    cout<<"1"<<endl;
    groupPhoto->push_back(photo);
    groupFilm->push_back(photo);
    groupPhoto->push_back(video);
    groupFilm->push_back(video);
  //  groupFilm->push_back(film);

    cout<<"2"<<endl;
    groupPhoto->affichage(cout);
    mo->deleteMultimedia("film");
    cout <<"film deleted"<< endl;
    groupPhoto->affichage(cout);

    cout<<"3"<<endl;
    mo->searchObject("hiver", cout);
    mo->playObject("t9ab4");
    mo->deleteGroupe("Groupe Photal");


    TCPServer * server = new TCPServer();
    MyApp * app = new MyApp(mo);
    server->setCallback(app, &MyApp::processRequest);

    int port = (argc >= 2) ? atoi(argv[1]) : 3331;
    cout << "Starting Server on port " << port << endl;
    int status = server->run(3331);

    if (status < 0) {
      cerr << "Could not start Server on port " << port << endl;
      return 1;
    }
    else return 0;

}
