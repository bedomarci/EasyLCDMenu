//
// Created by bedom on 10/10/2019.
//

#ifndef EASYLCDMENU_OPTIONMENUITEM_HPP
#define EASYLCDMENU_OPTIONMENUITEM_HPP

#include "ValueMenuItemTemplate.hpp"

template<uint8_t LENGTH>
class OptionMenuItem : public ValueMenuItemTemplate<uint8_t> {
public:
    OptionMenuItem(uint8_t *value, const char *label);

    OptionMenuItem(uint8_t *value, const char *label, const char *options[]);

    OptionMenuItem(uint8_t *value, const char *label, char **options);

    void setOptions(const char *options[]);

    void setOptions(char **options);

protected:
    char **_options;

    void toString(char *valueString) override;

    void increase() override;

    void decrease() override;


};

template<uint8_t LENGTH>
void OptionMenuItem<LENGTH>::toString(char *valueString) {
    strcpy(valueString, _options[getValue()]);
}

template<uint8_t LENGTH>
void OptionMenuItem<LENGTH>::increase() {
    int16_t newIndex = getValue() - 1;
    setValue(constrain(newIndex, 0, LENGTH-1));
}

template<uint8_t LENGTH>
void OptionMenuItem<LENGTH>::decrease() {
    int16_t newIndex = getValue() + 1;
    setValue(constrain(newIndex, 0, LENGTH-1));
}

template<uint8_t LENGTH>
void OptionMenuItem<LENGTH>::setOptions(const char *options[]) {
    _options = const_cast<char **>(options);
}

template<uint8_t LENGTH>
void OptionMenuItem<LENGTH>::setOptions(char **options) {
    _options = options;
}

template<uint8_t LENGTH>
OptionMenuItem<LENGTH>::OptionMenuItem(uint8_t *value, const char *label)
        : ValueMenuItemTemplate(value, label) {

}

template<uint8_t LENGTH>
OptionMenuItem<LENGTH>::OptionMenuItem(uint8_t *value, const char *label, const char **options) : OptionMenuItem(value, label) {
    setOptions(options);
}

template<uint8_t LENGTH>
OptionMenuItem<LENGTH>::OptionMenuItem(uint8_t *value, const char *label, char **options) : OptionMenuItem(value, label) {
    setOptions(options);
}


#endif //EASYLCDMENU_OPTIONMENUITEM_HPP
