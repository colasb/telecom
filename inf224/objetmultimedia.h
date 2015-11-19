#ifndef OBJETMULTIMEDIA_H
#define OBJETMULTIMEDIA_H
#include <iostream>
#include<string>

using namespace std;


class ObjetMultimedia
{
    string name;
    string pathname;

public:
    ObjetMultimedia();
    ObjetMultimedia(string nameObject, string pathnameObject);
    virtual string getName() const;
    virtual string getPathname() const;
    virtual void setName(string nameObject);
    virtual void setPathname(string pathnameOject);
    virtual void affichage(ostream& ostream) const;
    virtual void play() const =0;
    virtual string getAttribut();
    virtual ~ObjetMultimedia();

};

#endif // OBJETMULTIMEDIA_H
