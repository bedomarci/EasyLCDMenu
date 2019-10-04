//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_MENUITEM_H
#define EASYLCDMENU_MENUITEM_H
#include "../common.h"

<typename T>
class MenuItem {
public:
    virtual void render() = 0;
    virtual void change(EasyLCDMenuControl control) = 0;
    void setValue(T value);
    T getValue();

protected:
    T* value;
    const char * label;
    uint8_t icon;

};

<typename T>
inline void MenuItem::setValue(T value) {
    this.value = &value
}

<typename T>
inline T MenuItem::getValue() {
    return *value
}

#endif //EASYLCDMENU_MENUITEM_H
