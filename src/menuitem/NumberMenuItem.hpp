//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_NUMBERMENUITEM_HPP
#define EASYLCDMENU_NUMBERMENUITEM_HPP

#include "ValueMenuItemTemplate.hpp"

class NumberMenuItem : public ValueMenuItemTemplate<int> {
public:
    NumberMenuItem(int *value, const char *label, int minVal, int maxVal);
    int getStep() const;

    int getMinVal() const;

    void setMinVal(int minVal);

    int getMaxVal() const;

    void setMaxVal(int maxVal);

    void setStep(int step);

protected:
    void toString(char *valueString) override;

    void increase() override;

    void decrease() override;

    int _step = 1;
    int _minVal, _maxVal;
};

void NumberMenuItem::toString(char *valueString) {
    sprintf(valueString, "%d", this->getValue());
}

NumberMenuItem::NumberMenuItem(int *value, const char *label, int minVal = INT16_MIN, int maxVal = INT16_MAX)
        : ValueMenuItemTemplate(value, label) {
    this->setMinVal(minVal);
    this->setMaxVal(maxVal);

}

void NumberMenuItem::setStep(int step) {
    NumberMenuItem::_step = step;
}

int NumberMenuItem::getStep() const {
    return _step;
}

int NumberMenuItem::getMinVal() const {
    return _minVal;
}

void NumberMenuItem::setMinVal(int minVal) {
    NumberMenuItem::_minVal = minVal;
}

int NumberMenuItem::getMaxVal() const {
    return _maxVal;
}

void NumberMenuItem::setMaxVal(int maxVal) {
    NumberMenuItem::_maxVal = maxVal;
}

void NumberMenuItem::increase() {
    int newValue = this->getValue() + this->_step;
    this->setValue(constrain(newValue, _minVal, _maxVal));
}

void NumberMenuItem::decrease() {
    int newValue = this->getValue() - this->_step;
    this->setValue(constrain(newValue, _minVal, _maxVal));
}

#endif //EASYLCDMENU_NUMBERMENUITEM_HPP
