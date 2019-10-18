//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMANDMENUITEM_HPP
#define EASYLCDMENU_COMMANDMENUITEM_HPP

#include "ValueMenuItemTemplate.hpp"

class CommandMenuItem : public MenuItemTemplate<EasyLCDMenuFunction> {
public:
    CommandMenuItem(EasyLCDMenuFunction value, const char *label, const char *description = nullptr);

    void navigate(EasyLCDMenuControl control) override;

    void render(uint8_t **display, uint8_t rows, uint8_t columns) override;

    void setDescription(const char *description);

protected:
    EasyLCDMenuFunction _callback = nullptr;

    void toString(char *valueString);

    const char *_description;
};

void CommandMenuItem::navigate(EasyLCDMenuControl control) {
    switch (control) {
        case GO:
            if (getValue()){
                getValue()();
                this->getMenu()->home();
            }
            break;
        case BACK:
            this->leave();
            break;
        case NEXT:
        case PREVIOUS:
            break;
    }
}

CommandMenuItem::CommandMenuItem(EasyLCDMenuFunction value, const char *label, const char *description)
        : MenuItemTemplate(&value, label) {
    setDescription(description);
}

void CommandMenuItem::render(uint8_t **display, uint8_t rows, uint8_t columns) {
    this->setCursor(0, 0);
    this->print(display, this->getLabel());

    this->setCursor(this->getRows() - 1, 0);
    this->print(display, this->_description);

    this->setCursor(this->getRows() - 1, this->getColumns() - 1);
    this->print(display, EasyLCDMenuRight);
}

void CommandMenuItem::setDescription(const char *description) {
    _description = description;
}

#endif //EASYLCDMENU_COMMANDMENUITEM_HPP
