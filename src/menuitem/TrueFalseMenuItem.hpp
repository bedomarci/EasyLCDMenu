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

    void toString(char *valueString) override;

    void increase() override;

    void decrease() override;
};

void TrueFalseMenuItem::setTrueLabel(char *txt) {
    trueLabel = txt;
}

void TrueFalseMenuItem::setFalseLabel(char *txt) {
    falseLabel = txt;
}

void TrueFalseMenuItem::toString(char *valueString) {
    strcpy(valueString, (getValue()) ? trueLabel : falseLabel);
}

TrueFalseMenuItem::TrueFalseMenuItem(bool *value, const char *label) : ValueMenuItemTemplate<bool>(value, label) {

}

void TrueFalseMenuItem::increase() {
    setValue(!getValue());
}

void TrueFalseMenuItem::decrease() {
    setValue(!getValue());
}

#endif //EASYLCDMENU_TRUEFALSEMENUITEM_HPP
