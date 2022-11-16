#ifndef M2OEP_ESPRESSOITEM_H
#define M2OEP_ESPRESSOITEM_H

#include "CoffeeItem.h"

class EspressoItem : public CoffeeItem {
public:
    // Constructors
    EspressoItem();
    EspressoItem(string name);
    EspressoItem(string name, double price, int brewTime, int coffee, int espresso, int cocoaPowder, int steamedMilk);

    // Getter
    int getEspresso() const;

    // Setter
    void setEspresso(int espresso);

    // Get info
    string getInfo() const override;

private:
    // Single underscores after a variable name indicate it is a private/protected field of a class
    int espresso_;
};


#endif //M2OEP_ESPRESSOITEM_H
