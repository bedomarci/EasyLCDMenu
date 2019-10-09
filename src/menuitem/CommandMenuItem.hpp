//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMANDMENUITEM_HPP
#define EASYLCDMENU_COMMANDMENUITEM_HPP
#include "ValueMenuItemTemplate.hpp"

class CommandMenuItem : public ValueMenuItemTemplate<uint8_t> {
public:
    CommandMenuItem(uint8_t *value, const char *label);
    virtual void navigate(EasyLCDMenuControl control);
    void setCallback(EasyLCDMenuFunction cb);
protected:
    EasyLCDMenuFunction _callback = nullptr;
    void toString(char *valueString);
    uint8_t getStringLength();
};

void CommandMenuItem::navigate(EasyLCDMenuControl control) {
    switch (control) {
        case GO:
            if (_callback) {
                _callback();
                this->menu->home();
            }
        break;
        case BACK:
            this->leave();
        break;
    }
}

void CommandMenuItem::setCallback(EasyLCDMenuFunction cb) {
    _callback = cb;
}

void CommandMenuItem::toString(char *valueString) {

}

CommandMenuItem::CommandMenuItem(uint8_t *value, const char *label) : ValueMenuItemTemplate(value, label) {

}

#endif //EASYLCDMENU_COMMANDMENUITEM_HPP
