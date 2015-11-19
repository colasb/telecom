#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include<string>
#include "objetmultimedia.h"
#include "manageObject.h"
#include "TCPServer.h"
#include <sstream>

using namespace std;

class MyApp {
private:
    ManageObject *obj;
public:
    MyApp(ManageObject* obj);
    virtual bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response);
    virtual void processCommand(const string& request, string& name, string& response);
};

#endif // SERVER_H
