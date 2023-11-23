#ifndef RECEPTEUR_H
#define RECEPTEUR_H

#include <iostream>
#include <string>

using namespace std;

class Recepteur {
public:
    Recepteur(string name);
    void handleMessage(const string& message);
    string getName();
private:
    string name;
};


#endif
