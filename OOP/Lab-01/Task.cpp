#include <iostream>
using namespace std;


enum BuildingType { HOUSE, HOTEL, OFFICE };
enum CityName { LAHORE, KARACHI, ISLAMABAD };


struct Distance {
    
    int feet;
    int inches;

    void print() {
        cout << feet << "ft " << inches << "in";
    }
};

struct Room {
    string name;
    Distance length;
    Distance width;

    void print() {
        cout << "   " << name << ": ";
        length.print();
        cout << " x ";
        width.print();
        cout << endl;
    }
};

struct Floor {
    int number;
    Room kitchen;
    Room bedrooms[2];   

    void print() {
        cout << " Floor " << number << endl;
        kitchen.print();
        for (int i=0; i<2; i++) {
            bedrooms[i].print();
        }
    }
};

struct Building {
    BuildingType type;
    Floor floors[2];  

    void print() {
        if (type == HOUSE) cout << " Building: House\n";
        else if (type == HOTEL) cout << " Building: Hotel\n";
        else if (type == OFFICE) cout << " Building: Office\n";

        for (int i=0; i<2; i++) {
            floors[i].print();
        }
    }
};

struct Block {
    string name;
    Building buildings[2];  
    void print() {
        cout << "Block: " << name << endl;
        for (int i=0; i<2; i++) {
            buildings[i].print();
        }
    }
};

struct Colony {
    string name;
    Block blocks[2]; 

    void print() {
        cout << "Colony: " << name << endl;
        for (int i=0; i<2; i++) {
            blocks[i].print();
        }
    }
};

struct City {
    CityName city;
    Colony colonies[2];

    void print() {
        if (city == LAHORE) cout << "City: Lahore" << endl;
        else if (city == KARACHI) cout << "City: Karachi" << endl;
        else if (city == ISLAMABAD) cout << "City: Islamabad" << endl;

        for (int i=0; i<2; i++) {
            colonies[i].print();
        }
    }
};


int main()
{
    City myCity;
    myCity.city = LAHORE;


    myCity.colonies[0].name = "Colony A";
    myCity.colonies[0].blocks[0].name = "Block 1";
    myCity.colonies[0].blocks[1].name = "Block 2";

    myCity.colonies[1].name = "Colony B";
    myCity.colonies[1].blocks[0].name = "Block X";
    myCity.colonies[1].blocks[1].name = "Block Y";
}
