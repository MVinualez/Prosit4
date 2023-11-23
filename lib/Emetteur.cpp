#include "Emetteur.h"

#include <iostream>
#include <string>

using namespace std;

Emetteur::Emetteur() {
    this->instances = nullptr;
    this->handlers = nullptr;
    this->instancesCount = 0;
}

void Emetteur::registerInstance(Recepteur *instance, Emetteur::MessageHandler handler) {
    Recepteur** newInstances = new Recepteur*[instancesCount + 1];
    MessageHandler* newHandlers = new MessageHandler[instancesCount + 1];

    for (int i = 0; i < instancesCount; ++i) {
        newInstances[i] = instances[i];
        newHandlers[i] = handlers[i];
    }

    newInstances[instancesCount] = instance;
    newHandlers[instancesCount] = handler;

    instances = newInstances;
    handlers = newHandlers;
    instancesCount++;
}

void Emetteur::sendMessage(const string &message) {
    for (int i = 0; i < instancesCount; ++i) {
        (instances[i]->*handlers[i])(message);
    }
}

Emetteur::~Emetteur() {
    delete[] instances;
    delete[] handlers;
}
