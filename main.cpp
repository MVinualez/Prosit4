#include <iostream>
#include <string>

using namespace std;

class recepteur {
public:
    void handleMessage(const string& message) {
        cout << "Instance de recepteur : " << message << endl;
    }
};

class emetteur {
public:
    typedef void (recepteur::*MessageHandler)(const string&);

    emetteur() : instances(nullptr), handlers(nullptr), instancesCount(0) {}

    void registerInstance(recepteur* instance, MessageHandler handler) {
        recepteur** newInstances = new recepteur*[instancesCount + 1];
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

    void sendMessage(const string& message) {
        for (int i = 0; i < instancesCount; ++i) {
            (instances[i]->*handlers[i])(message);
        }
    }

    ~emetteur() {
        delete[] instances;
        delete[] handlers;
    }

private:
    recepteur** instances;
    MessageHandler* handlers;
    int instancesCount;
};

int main() {
    recepteur* r1 = new recepteur;
    recepteur* r2 = new recepteur;
    recepteur* r3 = new recepteur;

    emetteur e;

    e.registerInstance(r1, &recepteur::handleMessage);
    e.registerInstance(r2, &recepteur::handleMessage);
    e.registerInstance(r3, &recepteur::handleMessage);

    e.sendMessage("Bonjour!");

    delete r1;
    delete r2;
    delete r3;

    return 0;
}
