#ifndef PHOTO_H
#define PHOTO_H
#include <iostream>
#include<string>
#include "objetmultimedia.h"

using namespace std;

class Photo : public ObjetMultimedia
{
private:
    float latitude;
    float longitude;

public:
    Photo() : ObjetMultimedia() {latitude = 0.0; longitude = 0.0;}
    Photo(string namePhoto, string pathnamePhoto, float latitudePhoto, float longitudePhoto) : ObjetMultimedia(namePhoto, pathnamePhoto) {latitude =latitudePhoto; longitude = longitudePhoto;}
    virtual void setLatitude(float latitudePhoto){latitude = latitudePhoto;}
    virtual void setLongitude(float longitudePhoto){longitude = longitudePhoto;}
    virtual float getLongitude() const{return longitude;}
    virtual float getLatitude() const{return latitude;}
    virtual void affichage(ostream& ostream) const {ostream <<"le nom de la photo est "<<getName()<<endl;
                                                    ostream<<"le chemin d'acces' a la photo est "<<getPathname()<<endl;
                                                    ostream<<"la latitude est "<<latitude<<endl;
                                                    ostream<<"la longitude est "<<longitude<<endl;}
    virtual void play() const{system(("imagej " + getPathname() + "&").c_str()); }
    virtual ~Photo(){}
};

#endif // PHOTO_H
