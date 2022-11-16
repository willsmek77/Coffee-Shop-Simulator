#include <iostream>
#include "CoffeeItem.h"
#include "EspressoItem.h"

using namespace std;

bool testCoffeeItem();
bool testEspressoItem();

int main() {
    if (testCoffeeItem()) {
        cout << "Passed all CoffeeItem test cases" << endl;
    }
    if (testEspressoItem()) {
        cout << "Passed all EspressoItem test cases" << endl;
    }

    return 0;
}

bool testCoffeeItem() {
    bool passed = true;
    CoffeeItem c1;
    if (!c1.getName().empty() || c1.getPrice() != 0.00 || c1.getBrewTime() != 0) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
}

bool testEspressoItem() {

}