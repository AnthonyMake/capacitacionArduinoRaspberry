long tiempoVuelo, distancia;
const int pingPin = 7;	// pin Sig del sensor


void setup() {
  // inicio de la comunicacion Serial
  Serial.begin(9600);
}

void loop() {

  // Se declara el pin como salida
  pinMode(pingPin, OUTPUT);
  
  // Se forma el pulso de 5 microsegundos
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // se declara el pin como entrada
  pinMode(pingPin, INPUT);
  
  tiempoVuelo = pulseIn(pingPin, HIGH);

  // calculamos el valor en CM 
  distancia = tiempoVuelo / 29 / 2;

  // se muestra el resultado	
  Serial.print("Distancia: ");
  Serial.println(distancia);

  delay(100);
}
