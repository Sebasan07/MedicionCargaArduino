#include <LiquidCrystal_I2C.h> //incluimos la libreria para controlar nuestra pantalla lcd
LiquidCrystal_I2C lcd(0x27,16,2); // indicamos el tipo de pantalla a la libreria

int sensorPin = A0;    // variable del pin a0
int sv = 0;  // variable del valor medido en a0

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BIENVENIDO"); 
  lcd.setCursor(0,1);
  lcd.print("INICIEMOS");
  delay(3000);
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Carga:"); 
}

void loop() {  
  lcd.setCursor(0,1);
  lcd.print("                ");
  sv = analogRead(sensorPin); // leemos y almacenamos el valor medido en a0
  sv = map(sv,0,500,0,100); // mapeamos el valor medido en un rango de porcentajes de 0 a 100%
  lcd.setCursor(0,1);
  lcd.print(sv); // imprimimos el valor de la carga en la pantalla
  lcd.setCursor(3,1); // ajustamos la impresion de datos en la segunda fila de la pantalla y la cuarta columna para que no borre la impresion de la carga
  lcd.print("%"); // imprimimos el signo %
  delay(1000); //esperamos un segundo para tomar una nueva medicion
}
