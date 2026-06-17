#include <iostream>
using namespace std;

class Bread {
public:
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~Bread() 
    {

    }
};

class Burger {
public:
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~Burger() 
    {

    }
};

class Salad {
public:
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~Salad() 
    {  }
};

class Sauce {
public:
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~Sauce() 
    {  }
};

class Drink {
public:
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual ~Drink() 
    {  }
};

class WhiteBread : public Bread {
public:
    string getName() const override 
    { 
        return "White Bread"; 
    }
    double getPrice() const override 
    { return 50; }
};

class BrownBread : public Bread {
public:
    string getName() const override 
    { 
        return "Brown Bread"; 
    }
    double getPrice() const override 
    { return 60; }
};

class GarlicBread : public Bread {
public:
    string getName() const override 
    { 
        return "Garlic Bread"; 
    }
    double getPrice() const override 
    { return 80; }
};

class ChickenPatty : public Burger 
{
public:
    string getName() const override 
    { return "Chicken Patty"; }
    double getPrice() const override 
    { return 120; }
};

class BeefPatty : public Burger {
public:
    string getName() const override 
    { return "Beef Patty"; }
    double getPrice() const override 
    { return 150; }
};

class VegPatty : public Burger {
public:
    string getName() const override 
    { return "Veg Patty"; }
    double getPrice() const override 
    { return 100; }
};

class LettuceSalad : public Salad {
public:
    string getName() const override 
    { return "Lettuce Salad"; }
    double getPrice() const override 
    { return 30; }
};

class ColeslawSalad : public Salad {
public:
    string getName() const override 
    { return "Coleslaw Salad"; }
    double getPrice() const override 
    { return 40; }
};

class MixedVegSalad : public Salad {
public:
    string getName() const override 
    { return "Mixed Veg Salad"; }
    double getPrice() const override 
    { return 45; }
};

class MayoSauce : public Sauce {
public:
    string getName() const override 
    { return "Mayo Sauce"; }
    double getPrice() const override 
    { return 20; }
};

class KetchupSauce : public Sauce {
public:
    string getName() const override 
    { return "Ketchup Sauce"; }
    double getPrice() const override 
    { return 15; }
};

class MustardSauce : public Sauce {
public:
    string getName() const override 
    { return "Mustard Sauce"; }
    double getPrice() const override 
    { return 18; }
};

class ColaDrink : public Drink {
public:
    string getName() const override 
    { return "Cola Drink"; }
    double getPrice() const override 
    { return 60; }
};

class OrangeJuice : public Drink {
public:
    string getName() const override 
    { return "Orange Juice"; }
    double getPrice() const override 
    { return 70; }
};

class WaterBottle : public Drink {
public:
    string getName() const override 
    { return "Water Bottle"; }
    double getPrice() const override 
    { return 40; }
};

Bread* chooseBread() {
    int c;

    while (true) {
        cout << "\nChoose Bread:\n";
        cout << "1) White Bread\n2) Brown Bread\n3) Garlic Bread\nEnter choice: ";
        cin >> c;

        if (c == 1) return new WhiteBread();
        else if (c == 2) return new BrownBread();
        else if (c == 3) return new GarlicBread();
        else {
            cout << "Invalid choice... Enter 1-3 only!\n";
        }
    }
}

Burger* chooseBurger() {
    int c;
    while (true) {
        cout << "\nChoose Burger Patty:\n";
        cout << "1) Chicken Patty\n2) Beef Patty\n3) Veg Patty\nEnter choice: ";
        cin >> c;

        if (c == 1) return new ChickenPatty();
        else if (c == 2) return new BeefPatty();
        else if (c == 3) return new VegPatty();
        else cout << "Invalid choice... Enter 1-3 only!\n";
    }
}

Salad* chooseSalad() {
    int c;
    while (true) {
        cout << "\nChoose Salad:\n";
        cout << "1) Lettuce Salad\n2) Coleslaw Salad\n3) Mixed Veg Salad\nEnter choice: ";
        cin >> c;

        if (c == 1) return new LettuceSalad();
        else if (c == 2) return new ColeslawSalad();
        else if (c == 3) return new MixedVegSalad();
        else cout << "Invalid choice... Enter 1-3 only!\n";
    }
}

Sauce* chooseSauce() {
    int c;
    while (true) {
        cout << "\nChoose Sauce:\n";
        cout << "1) Mayo Sauce\n2) Ketchup Sauce\n3) Mustard Sauce\nEnter choice: ";
        cin >> c;

        if (c == 1) return new MayoSauce();
        else if (c == 2) return new KetchupSauce();
        else if (c == 3) return new MustardSauce();
        else cout << "Invalid choice... Enter 1-3 only!\n";
    }
}

Drink* chooseDrink() {
    int c;
    while (true) 
    {
        cout << "\nChoose Drink:\n";
        cout << "1) Cola Drink\n2) Orange Juice\n3) Water Bottle\nEnter choice: ";
        cin >> c;

        if (c == 1) return new ColaDrink();
        else if (c == 2) return new OrangeJuice();
        else if (c == 3) return new WaterBottle();
        else cout << "Invalid choice... Enter 1-3 only!\n";
    }
}

int main()
{

    cout << "\n";
    cout << "\" ______  Welcome to the Sandwich Vending Machine  ______ \"\n";
    cout << "\n";

    Bread* bread = chooseBread();
    Burger* burger = chooseBurger();
    Salad* salad = chooseSalad();
    Sauce* sauce = chooseSauce();
    Drink* drink = chooseDrink();

    cout << "\n\" ______   ORDER SUMMARY   ______ \"\n";
    cout << bread->getName() << " - " << bread->getPrice() << endl;
    cout << burger->getName() << " - " << burger->getPrice() << endl;
    cout << salad->getName() << " - " << salad->getPrice() << endl;
    cout << sauce->getName() << " - " << sauce->getPrice() << endl;
    cout << drink->getName() << " - " << drink->getPrice() << endl;

    double total = bread->getPrice() + burger->getPrice() +
                   salad->getPrice() + sauce->getPrice() +
                   drink->getPrice();

    cout << "\n";
    cout << "Total Price: " << total << endl;
    cout << "\n";
    cout << "Thank you for using the vending machine!!!! Peace out <3... \n";

    delete bread;
    delete burger;
    delete salad;
    delete sauce;
    delete drink;

    return 0;
}