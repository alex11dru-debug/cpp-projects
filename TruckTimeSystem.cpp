#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct Delivery {
    char destination[20];
    int timeMinutes;
};

class Truck {
private:
    char plate[10];
    Delivery deliveries[5];
    int count;

public:
    Truck();
    void addDelivery(const Delivery& d);
    int totalTime() const;
    void print() const;

    friend void readTruck(Truck& t);
};

void readDelivery(Delivery& d) {
    cout << "Enter destination and time: ";
    cin >> d.destination >> d.timeMinutes;
}

void readTruck(Truck& t) {
    cout << "Enter truck plate: ";
    cin >> t.plate;

    for (int i = 0; i < 5; i++) {
        Delivery d;
        readDelivery(d);
        t.addDelivery(d);
    }
}

Truck::Truck() {
    count = 0;
}

void Truck::addDelivery(const Delivery& d) {
    if (count == 5) {
        return;
    }
    deliveries[count] = d;
    count++;
}

int Truck::totalTime() const {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += deliveries[i].timeMinutes;
    }
    return total;
}

void Truck::print() const {
    cout << plate << " - Total time: " << totalTime() << endl;
}

int main() {
    int n;
    cout << "Number of trucks? ";
    cin >> n;

    Truck* list = new Truck[n];

    for (int i = 0; i < n; i++) {
        readTruck(list[i]);
    }

    for (int i = 0; i < n; i++) {
        list[i].print();
    }

    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (list[i].totalTime() < list[minIndex].totalTime()) {
            minIndex = i;
        }
    }
    cout << "Most efficient truck -> ";
    list[minIndex].print();

    delete[] list;
    return 0;
}
