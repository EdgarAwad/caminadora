#include "Adafruit_Keypad.h"

const byte ROWS = 5; // rows
const byte COLS = 2; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
    {'play', '2'},
    {'3', '4'},
    {'stop', '6'},
    {'mode', 'sube'},
    {'prog', 'baja'},

};
byte rowPins[ROWS] = {6, 7, 8, 9, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5};           //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
    customKeypad.begin();
}

void loop()
{
    // put your main code here, to run repeatedly:
    customKeypad.tick();

    while (customKeypad.available())
    {
        keypadEvent e = customKeypad.read();
        Serial.print((char)e.bit.KEY);
        if (e.bit.EVENT == KEY_JUST_PRESSED)
            Serial.println(" pressed");
        else if (e.bit.EVENT == KEY_JUST_RELEASED)
            Serial.println(" released");
    }

    delay(10);
}