//
// Created by m4800 on 10/8/2019.
//

#ifndef EASYLCDMENU_VALUEMENUITEMTEMPLATE_HPP
#define EASYLCDMENU_VALUEMENUITEMTEMPLATE_HPP

#include "MenuItem.hpp"

template<typename T>
class ValueMenuItemTemplate : public MenuItemTemplate<T> {
public:
    ValueMenuItemTemplate(T *value, const char *label);
    void render(uint8_t **display, uint8_t rows, uint8_t columns) override;
    virtual void navigate(EasyLCDMenuControl control) = 0;
protected:
    virtual void toString(char *valueString) = 0;
    virtual uint8_t getStringLength() = 0;
};

template<typename T>
void ValueMenuItemTemplate<T>::render(uint8_t **display, uint8_t rows, uint8_t columns) {
    setCursor(0, 0);
    this->print(display, this->_label);
    uint8_t strLen = getStringLength();
    if (strLen) {
        setCursor(getRows() - 1, getColumns() - strLen);
        char *valueString = new char[getColumns() + 1];
        this->toString(valueString);
        this->print(display, valueString);
    }
}

template<typename T>
ValueMenuItemTemplate<T>::ValueMenuItemTemplate(T *value, const char *label):MenuItemTemplate<T>(value, label) {

}

#endif //EASYLCDMENU_VALUEMENUITEMTEMPLATE_HPP
