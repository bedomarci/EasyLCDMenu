#include "Arduino.h"
#include "../../src/Menu.hpp"
#include "../../src/menuitem/SubMenuItem.hpp"
#include "../../src/menuitem/NumberMenuItem.hpp"

Menu menu;
SubMenuItem root;
double var1, var2, var3, var4, var5;

void setup() {
    root = new SubMenuItem();

    root.add(new NumberMenuItem(&var1, "VAR1"));
    root.add(new NumberMenuItem(&var2, "VAR2"));
    root.add(new NumberMenuItem(&var3, "VAR3"));
    root.add(new NumberMenuItem(&var4, "VAR4"));
    root.add(new NumberMenuItem(&var5, "VAR5"));
    menu.setRootMenuItem(root);
    menu.enter();
}
void loop() {

}
