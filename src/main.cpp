#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Menu.hpp"
#include "menuitem/SubMenuItem.hpp"
#include "menuitem/NumberMenuItem.hpp"

const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;

const int pin_BL = 10;

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

Menu menu(2,16);
SubMenuItem *root;
double var1, var2, var3, var4, var5;

void setup() {
    Serial.begin(9600);
    Serial.println("1");
    root = new SubMenuItem();
    Serial.println("2");
    lcd.begin(16,2);
    Serial.println("3");

    root->add(new NumberMenuItem(&var1, "VAR1"));
    root->add(new NumberMenuItem(&var2, "VAR2"));
    root->add(new NumberMenuItem(&var3, "VAR3"));
    root->add(new NumberMenuItem(&var4, "VAR4"));
    root->add(new NumberMenuItem(&var5, "VAR5"));
    //menu.setRootMenuItem(root);
    //menu.begin(&lcd);
//    lcd.print("HELLO");
    Serial.println("BEGIN");
    menu.enter();
    Serial.println("enterrrr");
}
void loop() {

}
