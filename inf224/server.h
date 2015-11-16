#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include<string>
#include "objetmultimedia.h"
#include "manageObject.h"
#include "TCPServer.h"


using namespace std;

class MyApp :
{
private:
    ManageObject *obj;
public:
    void MyApp(ManageObject _obj){ManageObject *obj = _obj;}
    virtual bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response);


};

#endif // SERVER_H
