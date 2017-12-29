boolean  estadoLed = false;

void setup() {
  
  pinMode(8, OUTPUT);  //declaro el pin 8 como salida
  pinMode(3, INPUT);  //declaro el pin 3 como entrada

}

void loop() {
  //pregunto si se ha presionado el boton en el pin 3
  if(digitalRead(3)){
    
    delay(50);            //espero a que el boton deje de rebotar
    estadoLed=!estadoLed; //cambio el estado del flag
  
  }
  
  digitalWrite(8,estadoLed);  //escribo el valor en el pin correspondiente
                              //al led

}
