#include "Recepteur.h"

void Recepteur::handleMessage(const string &message) {
    cout << this->getName() << " : " << message << endl;
}

string Recepteur::getName() {
    return this->name;
}

Recepteur::Recepteur(string name) {
    this->name = name;
}
