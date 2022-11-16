#include "CoffeeItem.h"

#include <utility>

/***** CoffeeItem class *****/

// Default constructor (delegates to full constructor)
CoffeeItem::CoffeeItem() : CoffeeItem("", 0.00, 0, 0, 0, 0) {}

// Single-parameter constructor (delegates to full constructor)
CoffeeItem::CoffeeItem(string name) : CoffeeItem(std::move(name), 0.00, 0, 0, 0, 0) {}

// Full constructor
CoffeeItem::CoffeeItem(string name, double price, int brewTime, int coffee, int cocoaPowder, int steamedMilk)
{
    name_ = std::move(name);
    price_ = price;
    brewTime_ = brewTime;
    coffee_ = coffee;
    cocoaPowder_ = cocoaPowder;
    steamedMilk_ = steamedMilk;
    purchaseCount_ = 0;
}

// Getters
string CoffeeItem::getName() const { return name_; }
double CoffeeItem::getPrice() const { return price_; }
int CoffeeItem::getBrewTime() const { return brewTime_; }
int CoffeeItem::getCoffee() const { return coffee_; }
int CoffeeItem::getCocoaPowder() const { return cocoaPowder_; }
int CoffeeItem::getSteamedMilk() const { return steamedMilk_; }

// Setters
void CoffeeItem::setName(const string& name) { name_ = name; }
void CoffeeItem::setPrice(double price) { price_ = price; }
void CoffeeItem::setBrewTime(int brewTime) { brewTime_ = brewTime; }
void CoffeeItem::setCoffee(int coffee) { coffee_ = coffee; }
void CoffeeItem::setCocoaPowder(int cocoaPowder) { cocoaPowder_ = cocoaPowder; }
void CoffeeItem::setSteamedMilk(int steamedMilk) { steamedMilk_ = steamedMilk; }

// Get info
string CoffeeItem::getInfo() const
{
    return "This is a coffee. Yum!";
}