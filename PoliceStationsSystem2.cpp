#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct Case {

    char caseCode[10];
    char crimeType[20];
    int daysOpen;
};

class Officer {

    private: 
         char name[30];
         Case cases[4];
         int count ;

    public: 
         Officer();
         void addCase(const Case& c);
         int totalDays() const;
         void print() const;

         friend void readOfficer(Officer& o);

};

void readCase(Case& c) {

    cout << "Enter Case code, and crime type days open :";
    cin >> c.caseCode >> c.crimeType >> c.daysOpen;
}

void readOfficer(Officer& o) {
    cout << "Enter name: ";
    cin >> o.name;

    for (int i = 0; i < 4; i++) {
        Case c;
        readCase(c);
        o.addCase(c);
    }
}

Officer::Officer() {
    count = 0;
}

void Officer::addCase(const Case& c) {
         
    if (count == 4) {
        return;
    }

    cases[count] = c;
    count++;
}

int Officer::totalDays() const {

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += cases[i].daysOpen;
    }
    return total;
}

void Officer::print() const {
    cout << name << " - Total days open: " << totalDays() << endl;
}

int main() {
    int n;
    cout << "Number of Officers? ";
    cin >> n;

    Officer* list = new Officer[n];

    for (int i = 0; i < n; i++) {
        readOfficer(list[i]);
    }

    for (int i = 0; i < n; i++) {
        list[i].print();

    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (list[i].totalDays() > list[maxIndex].totalDays()) {
            maxIndex = i;
        }
    }
    cout << " Bussines officer -> ";
    list[maxIndex].print();

    delete[] list;
    return 0;
}
