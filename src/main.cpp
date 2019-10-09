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
SubMenuItem *root;

int read_LCD_buttons();

int thisBtn = btnNONE, lastBtn = btnNONE;
double var1, var2, var3, var4, var5;

void setup() {
    Serial.begin(115200);
    root = new SubMenuItem(0,"SUBMENU");
    lcd.begin(16, 2);
    menu.setRootMenuItem(root);
    root->add(new NumberMenuItem(&var1, "VAR1"));
    root->add(new NumberMenuItem(&var2, "VAR2"));
    root->add(new NumberMenuItem(&var3, "VAR3"));
    root->add(new NumberMenuItem(&var4, "VAR4"));
    root->add(new NumberMenuItem(&var5, "VAR5"));

    menu.begin(&lcd);
//    lcd.print("HELLO");
    Serial.println("BEGIN");
    menu.enter();
}
void loop() {
    thisBtn = read_LCD_buttons();
    if (thisBtn!=lastBtn) {
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

    lastBtn = thisBtn;
    delay(50);
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

