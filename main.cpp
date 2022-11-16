#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <ctime>
#include "CoffeeItem.h"
#include "EspressoItem.h"
using namespace std;

struct {
    double money = 10.00;
    int groundCoffee = 0;
    int cocoaPowder = 0;
    int steamedMilk = 0;
    vector<unique_ptr<CoffeeItem>> menu;
    int customersServed = 0;
} player;

void startGame();
void printHowToPlay();
void printPlayer();
void printChoices();
char getChoiceInput();
void waitForPlayer();
void serveNextCustomer();
void purchaseMaterials();
void upgradeShop();

int main() {
    // Create the menu. Each menu item will be stored in the vector, and is optional for any removed items.
//    unique_ptr<vector<optional<MenuItem>>> menu = make_unique<vector<optional<MenuItem>>>();
    // Create the menu. Each element of the vector is a unique pointer, which allows for proper polymorphism
//    vector<unique_ptr<CoffeeItem>> menu;

    // Add black coffee to the menu
    CoffeeItem black("black");
    black.setCoffee(8);
    black.setCocoaPowder(0);
    black.setSteamedMilk(0);
    black.setBrewTime(1);
    black.setPrice(1.25);
    player.menu.push_back(make_unique<CoffeeItem>(black));

    // Add cafe au lait to the menu
    CoffeeItem cafeAuLait("cafe au lait");
    cafeAuLait.setCoffee(5);
    cafeAuLait.setCocoaPowder(0);
    cafeAuLait.setSteamedMilk(5);
    cafeAuLait.setBrewTime(3);
    cafeAuLait.setPrice(1.50);
    player.menu.push_back(make_unique<CoffeeItem>(cafeAuLait));

    // Add iced coffee to the menu
    CoffeeItem icedCoffee("iced coffee");
    icedCoffee.setCoffee(6);
    icedCoffee.setCocoaPowder(1);
    icedCoffee.setSteamedMilk(0);
    icedCoffee.setBrewTime(3);
    icedCoffee.setPrice(1.50);
    player.menu.push_back(make_unique<CoffeeItem>(icedCoffee));

    // Add espresso to the menu
    EspressoItem espresso("espresso");
    espresso.setCoffee(0);
    espresso.setEspresso(1);
    espresso.setCocoaPowder(0);
    espresso.setSteamedMilk(0);
    espresso.setBrewTime(1);
    espresso.setPrice(1.25);
    player.menu.push_back(make_unique<EspressoItem>(espresso));

    // Add double espresso to the menu
    EspressoItem doubleEspresso("double espresso");
    doubleEspresso.setCoffee(0);
    doubleEspresso.setEspresso(2);
    doubleEspresso.setCocoaPowder(0);
    doubleEspresso.setSteamedMilk(0);
    doubleEspresso.setBrewTime(1);
    doubleEspresso.setPrice(1.50);
    player.menu.push_back(make_unique<EspressoItem>(doubleEspresso));

    // Add red eye to the menu
    EspressoItem redEye("red eye");
    redEye.setCoffee(6);
    redEye.setEspresso(1);
    redEye.setCocoaPowder(0);
    redEye.setSteamedMilk(0);
    redEye.setBrewTime(2);
    redEye.setPrice(1.50);
    player.menu.push_back(make_unique<EspressoItem>(redEye));

    // Add macchiato to the menu
    EspressoItem macchiato("macchiato");
    macchiato.setCoffee(0);
    macchiato.setEspresso(1);
    macchiato.setCocoaPowder(0);
    macchiato.setSteamedMilk(1);
    macchiato.setBrewTime(2);
    macchiato.setPrice(1.50);
    player.menu.push_back(make_unique<EspressoItem>(macchiato));

    // Add cappuccino to the menu
    EspressoItem cappuccino("cappuccino");
    cappuccino.setCoffee(0);
    cappuccino.setEspresso(1);
    cappuccino.setCocoaPowder(1);
    cappuccino.setSteamedMilk(2);
    cappuccino.setBrewTime(3);
    cappuccino.setPrice(1.75);
    player.menu.push_back(make_unique<EspressoItem>(cappuccino));

    // Add cafe latte to the menu
    EspressoItem cafeLatte("caffe latte");
    cafeLatte.setCoffee(0);
    cafeLatte.setEspresso(1);
    cafeLatte.setCocoaPowder(0);
    cafeLatte.setSteamedMilk(8);
    cafeLatte.setBrewTime(2);
    cafeLatte.setPrice(1.75);
    player.menu.push_back(make_unique<EspressoItem>(cafeLatte));

    // Add mocha to the menu
    EspressoItem mocha("mocha");
    mocha.setCoffee(0);
    mocha.setEspresso(1);
    mocha.setCocoaPowder(2);
    mocha.setSteamedMilk(2);
    mocha.setBrewTime(3);
    mocha.setPrice(1.75);
    player.menu.push_back(make_unique<EspressoItem>(mocha));


//    // Start game
//    Game game;
//    game.start();
    startGame();


//    menu->push_back(make_optional<MenuItem>());
//    auto test = menu->end();
//    test->value().setName("espresso");
//
//    cout << test->value().getName() << endl;
//
//    cout << (*menu)[0]->getName() << endl;




    return 0;
}

void startGame() {
    srand(time(NULL));

    cout << "Welcome to your new coffee shop!" << endl;
    cout << "Your beloved parents just bought you this shop to get you started. It comes with all the " << endl;
    cout << "machinery you need to brew a wide variety of items. Unfortunately, it looks like they forgot to " << endl;
    cout << "provide you with ground coffee, or with any of the other food materials you need." << endl;
    waitForPlayer();
    printHowToPlay();
    waitForPlayer();
    cout << endl;

    bool retired = false;
    while(!retired)
    {
        printChoices();
        char choice = getChoiceInput();
        switch (choice) {
            case 's':
                serveNextCustomer();
                break;
            case 'p':
                purchaseMaterials();
                break;
            case 'u':
                upgradeShop();
                break;
            case 'v':
                printPlayer();
                break;
            case 'r':
                retired = true;
                break;
            default:
                break;
        }
    }

    cout << endl;
    cout << "Hopefully you've enjoyed your time as a coffee shop owner and lived a prosperous life!" << endl;
    cout << "You retired with $" << fixed << setprecision(2) << player.money << " to your name!" << endl;
}

void printHowToPlay() {
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "How to play:" << endl;
    cout << "  > Use your money to progress! Money can be used to buy raw materials, upgrade aspects of your " << endl;
    cout << "    shop to attract higher-paying customers, or to buy collectables that you can bring home." << endl;
    cout << "  > Make sure you have enough supplies. If you run out of stock on an item, you won't be able to " << endl;
    cout << "    serve some customers." << endl;
    cout << "  > You can choose what to do next by entering a character when prompted." << endl;
    cout << "  > Have fun making coffee and improving your coffee shop!" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
}

void printPlayer() {
    cout << "~=~=~=~=~   Your Stats   ~=~=~=~=~" << endl;
    cout << "Money: $" << fixed << setprecision(2) << player.money << endl;
    cout << "Ground coffee: " << player.groundCoffee << " grams" << endl;
    cout << "Cocoa powder: " << player.cocoaPowder << " grams" << endl;
    cout << "Steamed milk: " << player.steamedMilk << " fl oz" << endl;
    cout << "~=~=~=~=~=~=~=~==~=~=~=~=~=~=~=~=~" << endl;
}

void printChoices() {
    cout << "Choose an action:" << endl;
    cout << "(s)erve customer  //  (p)urchase materials  //  (u)pgrade shop  //  (v)iew stats  //  (r)etire" << endl;
}

char getChoiceInput() {
    // Prompt user
    cout << "Enter a single character: ";
    string input;
    getline(cin, input);

    // Re-prompt user if no input
    if (input.empty())
    {
        cout << "No input. ";
        return getChoiceInput();
    }

    // Re-prompt user if input is more than one character
    if (input.length() > 1)
    {
        cout << "Invalid input. ";
        return getChoiceInput();
    }

    // Re-prompt user if character isn't among valid choices
    char inputAsChar = input[0];
    if (!(inputAsChar == 's' || inputAsChar == 'p' || inputAsChar == 'u' || inputAsChar == 'v' || inputAsChar == 'r'))
    {
        cout << "Invalid character. ";
        return getChoiceInput();
    }

    // Return input as char
    return inputAsChar;
}

void waitForPlayer() {
    cout << "Press enter to continue...";
    cin.get();
}

void serveNextCustomer() {
    ++player.customersServed;
    int numItems = player.menu.size();
    int itemIdx = rand() % numItems;

    cout << endl;
    cout << "Customer #" << player.customersServed << " says, \"Hi! I'd like one " << player.menu[itemIdx]->getName() << ", please.\"" << endl;
    cout << player.menu[itemIdx]->getInfo() << endl; // Demonstrates polymorphism
    cout << "The rest of this function is not currently implemented." << endl;
    cout << endl;
}

void purchaseMaterials() {
    cout << "This functionality is not currently implemented." << endl;
}

void upgradeShop() {
    cout << "This functionality is not currently implemented." << endl;
}