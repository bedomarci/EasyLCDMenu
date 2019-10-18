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

    void navigate(EasyLCDMenuControl control);

protected:
    virtual void toString(char *valueString) = 0;

    virtual void increase() = 0;

    virtual void decrease() = 0;
};

template<typename T>
void ValueMenuItemTemplate<T>::navigate(EasyLCDMenuControl control) {
    switch (control) {
        case NEXT:
            increase();
            this->getMenu()->render(NONE);
            break;
        case PREVIOUS:
            decrease();
            this->getMenu()->render(NONE);
            break;
        case GO:
            break;
        case BACK:
            this->leave();
            break;
    }
}

template<typename T>
void ValueMenuItemTemplate<T>::render(uint8_t **display, uint8_t rows, uint8_t columns) {
    this->setCursor(0, 0);
    this->print(display, this->getLabel());

    char *valueString = new char[this->getColumns() + 1];
    this->toString(valueString);
    this->setCursor(this->getRows() - 1, 0);
    this->print(display, EasyLCDMenuLeft);

    uint8_t strLen = strlen(valueString);
    Serial.println(valueString);
    this->setCursor(this->getRows() - 1, this->getColumns() - strLen);
    this->print(display, valueString);

}

template<typename T>
ValueMenuItemTemplate<T>::ValueMenuItemTemplate(T *value, const char *label):MenuItemTemplate<T>(value, label) {

}

#endif //EASYLCDMENU_VALUEMENUITEMTEMPLATE_HPP
