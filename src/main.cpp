#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Menu.hpp"
#include "menuitem/SubMenuItem.hpp"
#include "menuitem/NumberMenuItem.hpp"
#include "menuitem/TrueFalseMenuItem.hpp"
#include "menuitem/OptionMenuItem.hpp"

const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;

int adc_key_in = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

const int pin_BL = 10;

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

Menu menu(2,16);

void home();
SubMenuItem *root;
OptionMenuItem<3> *option1;

int read_LCD_buttons();

int thisBtn = btnNONE, lastBtn = btnNONE;
int var1, var2, var3, var4, var5;
bool bool1;
uint8_t opt1;
const char *optionLabels[] = {"Elso", "Második", "óüöúőűáéí"};

void setup() {
    Serial.begin(115200);
    root = new SubMenuItem(0,"SUBMENU");
    lcd.begin(16, 2);
    menu.setRootMenuItem(root);
    root->add(new NumberMenuItem(&var1, "VAR1", -2, 5));
    root->add(new TrueFalseMenuItem(&bool1, "BOOL2"));

    option1 = new OptionMenuItem<3>(&opt1, "OPT3");
    option1->setOptions(optionLabels);
    root->add(option1);
    root->add(new NumberMenuItem(&var4, "VAR4"));
    root->add(new NumberMenuItem(&var5, "VAR5"));

    menu.begin(&lcd);
    Serial.println("BEGIN");
    menu.onHome(home);
    menu.enter();
}
void loop() {
    thisBtn = read_LCD_buttons();
    if (thisBtn!=lastBtn) {
        if (!menu.isActive()) {
            if (thisBtn == btnSELECT) {
                menu.enter();
                Serial.println("entering menu.");
            }
        } else {
            switch (thisBtn) {
                case btnDOWN:
                    menu.previous();
                    break;
                case btnUP:
                    menu.next();
                    break;
                case btnLEFT:
                    menu.back();
                    break;
                case btnRIGHT:
                case btnSELECT:
                    menu.go();
                    break;
            }
        }
    }
    lastBtn = thisBtn;
    delay(50);
}

void home() {
    lcd.clear();
    lcd.home();
    lcd.print("HOME");
    Serial.println("arriving home");
}


// read the buttons
int read_LCD_buttons() {
    adc_key_in = analogRead(A0);      // read the value from the sensor
    if (adc_key_in > 1000)
        return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
    if (adc_key_in < 50) return btnRIGHT;
    if (adc_key_in < 250) return btnUP;
    if (adc_key_in < 450) return btnDOWN;
    if (adc_key_in < 650) return btnLEFT;
    if (adc_key_in < 850) return btnSELECT;
    return btnNONE;  // when all others fail, return this...
}

