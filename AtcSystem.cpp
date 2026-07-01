#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct Contact {
    char callsign[10];
    char squawk[5];
    int altidudeFeet;
};

class Controller {
private:
    char name[30];
    Contact contacts[5];
    int count;

public:
    Controller();
    void logContact(const Contact& c);
    int totalAltitude() const;
    void print() const;

    friend void readController(Controller& ctrl);
};

void readContact(Contact& c) {
    cout << "Enter callsign, squawk and altidudeFeet: ";
    cin >> c.callsign >> c.squawk >> c.altidudeFeet;
}

void readController(Controller& ctrl) {
    cout << "Enter controller name: ";
    cin >> ctrl.name;

    for (int i = 0; i < 5; i++) {
        Contact c;
        readContact(c);
        ctrl.logContact(c);
    }
}

Controller::Controller() {
    count = 0;
}

void Controller::logContact(const Contact& c) {
    if (count == 5) {
        return;
    }
    contacts[count] = c;
    count++;
}

int Controller::totalAltitude() const {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += contacts[i].altidudeFeet;
    }
    return total;
}

void Controller::print() const {
    cout << name << " - Total altitude: " << totalAltitude() << endl;
}

int main() {
    int n;
    cout << "Number of controllers? ";
    cin >> n;

    Controller* list = new Controller[n];

    for (int i = 0; i < n; i++) {
        readController(list[i]);
    }

    for (int i = 0; i < n; i++) {
        list[i].print();
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (list[i].totalAltitude() > list[maxIndex].totalAltitude()) {
            maxIndex = i;
        }
    }
    cout << "Busiest controller -> ";
    list[maxIndex].print();

    delete[] list;
    return 0;
}
