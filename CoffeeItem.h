#ifndef M1OEP_COFFEEITEM_H
#define M1OEP_COFFEEITEM_H

#include <string>
using std::string;

class CoffeeItem {
public:
    // Constructors
    CoffeeItem();
    explicit CoffeeItem(string name);
    CoffeeItem(string name, double price, int brewTime, int coffee, int cocoaPowder, int steamedMilk);

    // Getters
    string getName() const;
    double getPrice() const;
    int getBrewTime() const;
    int getCoffee() const;
    int getCocoaPowder() const;
    int getSteamedMilk() const;

    // Setters
    void setName(const string& name);
    void setPrice(double price);
    void setBrewTime(int brewTime);
    void setCoffee(int coffee);
    void setCocoaPowder(int cocoaPowder);
    void setSteamedMilk(int steamedMilk);

    // Get info
    virtual string getInfo() const;

protected:
    // Single underscores after a variable name indicate it is a private/protected field of a class
    string name_; // Name of item
    double price_; // Price of item
    int brewTime_; // Time to brew (min)
    int coffee_; // Amount of coffee required to brew (grams)
    int cocoaPowder_; // Amount of cocoa powder required to brew (grams)
    int steamedMilk_; // Amount of steamed milk required to brew (fl oz)
    mutable int purchaseCount_; // Number of times purchased
};


#endif //M1OEP_COFFEEITEM_H
