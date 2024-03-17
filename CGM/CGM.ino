#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (you may need to adjust this based on your LCD's actual address)
#define LCD_ADDRESS 0x7C

// Set the number of columns and rows for your LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS); // Initialize the LCD

const int gasSensorPin = A0; // MQ-6 Gas Sensor output pin
const int heartRatePin = A1; // Heart rate monitor output pin

void setup() {
  lcd.begin(); // Initialize the LCD
  lcd.backlight();  // Turn on the backlight

  pinMode(gasSensorPin, INPUT);
  pinMode(heartRatePin, INPUT);
}

void loop() {
  int gasLevel = analogRead(gasSensorPin);
  int heartRate = analogRead(heartRatePin);

  lcd.clear(); // Clear the LCD screen

  lcd.setCursor(0, 0);
  lcd.print("Glucose Level: ");
  lcd.print(gasLevel);

  lcd.setCursor(0, 1);
  lcd.print("Heart Rate: ");
  lcd.print(heartRate);

  delay(1000); // Wait for a second before updating readings
}
