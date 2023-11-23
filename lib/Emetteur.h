#ifndef EMETTEUR_H
#define EMETTEUR_H

#include "Recepteur.h"
#include <iostream>
#include <string>

using namespace std;

class Emetteur {
public:
    typedef void (Recepteur::*MessageHandler)(const string&);
    Emetteur();
    void registerInstance(Recepteur* instance, MessageHandler handler);
    void sendMessage(const string& message);
    ~Emetteur();

private:
    Recepteur** instances;
    MessageHandler* handlers;
    int instancesCount;
};


#endif
