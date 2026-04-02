#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Cambiar 0x27 por la dirección encontrada con el scanner si fuera necesario
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinEntrada = A0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();
}

void loop() {
  // 1) Leer ADC
  int lecturaADC = analogRead(pinEntrada);  // 0 a 1023

  // 2) Convertir a porcentaje del canal 1
  int canal1 = map(lecturaADC, 0, 1023, 0, 100);

  // 3) Complemento para canal 2
  int canal2 = 100 - canal1;

  // 4) Mostrar en LCD
  lcd.setCursor(0, 0);
  lcd.print("Canal 1: ");
  lcd.print(canal1);
  lcd.print("%   "); // espacios para borrar residuos

  lcd.setCursor(0, 1);
  lcd.print("Canal 2: ");
  lcd.print(canal2);
  lcd.print("%   ");

  // 5) Mostrar por Serial para depuracion
  Serial.print("ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | Canal 1: ");
  Serial.print(canal1);
  Serial.print("% | Canal 2: ");
  Serial.print(canal2);
  Serial.println("%");

  delay(200);
}