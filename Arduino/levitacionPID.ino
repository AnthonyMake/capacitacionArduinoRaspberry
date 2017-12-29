 #include <PID_v1.h>

const int pingPin = 7;            //Ultrasonic sensor Pin
const int fanPin  = 8;            //Actuator Pin (fan)
const int potPin  = 5;            //Potentiometer to set the Sp

double Sp, Pv, Mv;                //Values for PID control

//Compensator Values
double kp = 5;                    //Proportional
double ki = 3;                    //Integral
double kd = 3;                    //Derivative

//Compensator declaration
PID myPID(&Pv, &Mv, &Sp, kp, ki, kd, REVERSE);

void setup() {
  
  Serial.begin(9600);
  
  Pv = 29;                  //initial PV Value to trigger the actuator.
  Sp = 18;                  //initial SetPoint
  
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0,255);

}

void loop() {
  
  Sp = map(analogRead(potPin),0,1023,3,29);
  Pv = usonicMeas();
  
  myPID.Compute();
  
  analogWrite(fanPin,Mv);

  showVariables();          //list Sp,Pv and Mv on Serial Monitor
  
}

long usonicMeas(){

  //shape the pulse
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);             
  delayMicroseconds(2);         
  digitalWrite(pingPin, HIGH);  
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  //Measure Time of Flight
  
  pinMode(pingPin, INPUT);                //act as input
  long duration = pulseIn(pingPin, HIGH); //Read the pulse
  return duration / 29 / 2;               //return value in centimeters
  
}

void showVariables(){
  
  Serial.print(Sp);
  Serial.print(", ");
  Serial.print(Pv);
  Serial.print(", ");
  Serial.println(Mv);  

}
