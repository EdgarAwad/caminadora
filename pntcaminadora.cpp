
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("Cima ltda");
  lcd.setCursor(4,1);
  lcd.print("Mantenimiento");
   lcd.setCursor(10,2);
  lcd.print("&");
   lcd.setCursor(5,3);
  lcd.print("Desarrollo");
}


void loop()
{
}
