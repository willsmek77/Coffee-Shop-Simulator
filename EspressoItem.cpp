#include "EspressoItem.h"

#include <utility>

/***** EspressoItem class *****/

// Default constructor (delegates to full CoffeeItem constructor)
EspressoItem::EspressoItem() : CoffeeItem("", 0.00, 0, 0, 0, 0), espresso_(0) {}

// Single-parameter constructor (delegates to full CoffeeItem constructor)
EspressoItem::EspressoItem(string name) : CoffeeItem(std::move(name), 0.00, 0, 0, 0, 0), espresso_(0) {}

// Full constructor (delegates to full CoffeeItem constructor)
EspressoItem::EspressoItem(string name, double price, int brewTime, int coffee, int espresso, int cocoaPowder, int steamedMilk)
                          : CoffeeItem(std::move(name), price, brewTime, coffee, cocoaPowder, steamedMilk), espresso_(espresso) {}

// Getter
int EspressoItem::getEspresso() const { return espresso_; }

// Setter
void EspressoItem::setEspresso(int espresso) { espresso_ = espresso; }

// Get info
string EspressoItem::getInfo() const
{
    return "This is an espresso. Wow!";
}