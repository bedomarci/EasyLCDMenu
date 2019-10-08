//
// Created by m4800 on 10/8/2019.
//

#ifndef EASYLCDMENU_TRUEFALSEMENUITEM_HPP
#define EASYLCDMENU_TRUEFALSEMENUITEM_HPP

#include "ValueMenuItemTemplate.hpp"

class TrueFalseMenuItem : public ValueMenuItemTemplate<bool> {
public:
    TrueFalseMenuItem(bool *value, const char *label);
    void setTrueLabel(char *txt);
    void setFalseLabel(char *txt);
protected:
    char *trueLabel  = const_cast<char *>(EasyLCDMenuTrue);
    char *falseLabel = const_cast<char *>(EasyLCDMenuFalse);
    void toString(char *valueString);
    uint8_t getStringLength();
};

void TrueFalseMenuItem::setTrueLabel(char *txt) {
    trueLabel = txt;
}

void TrueFalseMenuItem::setFalseLabel(char *txt) {
    falseLabel = txt;
}

void TrueFalseMenuItem::toString(char *valueString) {
    memcpy(
            valueString,
            (_value) ? trueLabel : falseLabel,
            (_value) ? strlen(trueLabel) : strlen(falseLabel)
    );
}

uint8_t TrueFalseMenuItem::getStringLength() {
    return (_value) ? strlen(trueLabel) : strlen(falseLabel);
}

TrueFalseMenuItem::TrueFalseMenuItem(bool *value, const char *label) : ValueMenuItemTemplate<bool>(value, label) {

}

#endif //EASYLCDMENU_TRUEFALSEMENUITEM_HPP
