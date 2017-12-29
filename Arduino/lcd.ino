// declaracion de pines para el LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Creacion del objeto LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Inicializacion de un LCD 16 columnas y 2 filas
  lcd.begin(16, 2);
  
  // Esribe el mensaje en la pantalla del LCD
  // En la Posicion 0,0
  lcd.print("hello, world!");
}

void loop() {
  // ponemos el cursor en la columna 0, fila 1
  // linea 1 es la segunda fila, comienzan en 0:
  lcd.setCursor(0, 1);
  
  // muestra un conteo de tiempo:
  lcd.print(millis() / 1000);
}
