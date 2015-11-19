#ifndef GROUPE_H
#define GROUPE_H

#include <list>
using namespace std;
template <class T>

class Groupe : public list<T> {
private :
    string name;

public :
    Groupe(string name) : list<T>() { this->name = name;}
    string getName() const {return name;}

    void affichage(ostream & cout) const {
        for(auto it = this->begin(); it != this->end(); it++){ (*it) ->affichage(cout); cout <<"\n"<<endl;}
    }

    void play() const {
        for(auto it = this->begin(); it != this->end(); it++){ (*it) ->play(); cout <<"\n"<<endl;}
    }   
    virtual ~Groupe(){cout<<"The group "<<this->name<<" was delete"<<endl;}
};

#endif // GROUPE_H
