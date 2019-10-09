//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_NUMBERMENUITEM_HPP
#define EASYLCDMENU_NUMBERMENUITEM_HPP

#include "ValueMenuItemTemplate.hpp"

class NumberMenuItem : public ValueMenuItemTemplate<double> {
public:
    NumberMenuItem(double *value, const char *label);
    void navigate(EasyLCDMenuControl control) override;
protected:
    void toString(char *valueString) override;
    uint8_t getStringLength() override;
    double  step;
    uint8_t stringLength = 0;
};

void NumberMenuItem::navigate(EasyLCDMenuControl control) {
    switch (control) {
        case NEXT:
            *this->_value += this->step;
            break;
        case PREVIOUS:
            *this->_value -= this->step;
            break;
        case GO:
        case BACK:
            leave();
            break;
    }
}

void NumberMenuItem::toString(char *valueString) {
    stringLength = sprintf(valueString, "%.2f", this->getValue());
}

uint8_t NumberMenuItem::getStringLength() {
    return this->stringLength;
}

NumberMenuItem::NumberMenuItem(double *value, const char *label) : ValueMenuItemTemplate(value, label) {

}

#endif //EASYLCDMENU_NUMBERMENUITEM_HPP
