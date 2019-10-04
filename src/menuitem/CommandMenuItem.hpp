//
// Created by m4800 on 10/4/2019.
//

#ifndef EASYLCDMENU_COMMANDMENUITEM_HPP
#define EASYLCDMENU_COMMANDMENUITEM_HPP
#include "NumberMenuItem.hpp"

class CommandMenuItem : public MenuItem<double> {
public:
    void render();
    void change(EasyLCDMenuControl control);
protected:
    EasyLCDMenuFunction callback;

};
#endif //EASYLCDMENU_COMMANDMENUITEM_HPP
