#include <SoftI2CMaster.h>
#include <LiquidCrystal_I2C.h>

// Définir les broches SDA et SCL personnalisées
const int SDA_PIN = 0;
const int SCL_PIN = 1;

// Définir l'adresse de l'écran LCD
const int LCD_ADDRESS = 0x27; // Changez cette adresse si nécessaire

// Définir le nombre de colonnes et de lignes de l'écran LCD
const int LCD_COLUMNS = 16;
const int LCD_ROWS = 2;

// Initialiser la bibliothèque LCD avec la communication I2C logicielle
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS, SDA_PIN, SCL_PIN);

void setup() {
  // Initialiser l'écran LCD
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  // Allumer le rétroéclairage
  lcd.backlight();
  // Afficher "Hello" sur l'écran LCD
  lcd.print("Hello");
}

void loop() {
  // Boucle vide
}

