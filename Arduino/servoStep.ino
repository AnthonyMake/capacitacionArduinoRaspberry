#include <Servo.h>
 
// Declaramos el objeto servo
Servo servoMotor;
 
void setup() { 
  // se inicializa el servo en el pin 9
  servoMotor.attach(9);
}
 
void loop() {
  
  // posicion 0 grad
  servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  
  // posicion 90 grad
  servoMotor.write(90);
  // Esperamos 1 segundo
  delay(1000);
  
  // posicion 180 grad
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);
}
