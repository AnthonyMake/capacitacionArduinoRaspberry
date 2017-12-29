int medicion;

void setup(){
	Serial.begin(9600);
}

void loop(){
	medicion=analogRead(A2);
	
	Serial.print("Valor Medido: ");
	Serial.println(medicion);
	delay(200);
}
