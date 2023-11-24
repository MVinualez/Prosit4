#include <string>
#include "lib/Recepteur.h"
#include "lib/Emetteur.h"

using namespace std;


int main() {
    Recepteur* r1 = new Recepteur("Rodrigo");
    Recepteur* r2 = new Recepteur("Roberta");
    Recepteur* r3 = new Recepteur("Hubert");
    Recepteur* r4 = new Recepteur("Jacques");

    Emetteur*  e = new Emetteur();

    e->registerInstance(r1, &Recepteur::handleMessage);
    e->registerInstance(r2, &Recepteur::handleMessage);
    e->registerInstance(r3, &Recepteur::handleMessage);

    e->sendMessage("Bonjour!");

    e->registerInstance(r4, &Recepteur::handleMessage);

    e->sendMessage("Bienvenue!");

    delete r1;
    delete r2;
    delete r3;

    return 0;
}
