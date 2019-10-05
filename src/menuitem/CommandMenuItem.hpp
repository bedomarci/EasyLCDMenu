//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMANDMENUITEM_HPP
#define EASYLCDMENU_COMMANDMENUITEM_HPP
#include "MenuItem.hpp"

class CommandMenuItem : public MenuItem<double> {
public:
    void render();
    void navigate(EasyLCDMenuNavigation navigation);
protected:
    EasyLCDMenuFunction callback;

};
#endif //EASYLCDMENU_COMMANDMENUITEM_HPP
