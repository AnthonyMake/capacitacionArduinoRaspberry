int byteEntrante;      	// aqui guardamos el valor que 
						//entra en el puerto serie

void setup()
{
	//se inicia la comunicacion Serial
    Serial.begin(9600);
    //se declara el pin para el led como salida
    pinMode(9, OUTPUT);
}

void loop()
{
    // se esperan datos en el puerto serie
    if (Serial.available() > 0)
    {
        // leemos el primer byte del buffer
        byteEntrante = Serial.read();
        // si llega una H encendemos el led
        if (byteEntrante == 'H')
        {
            digitalWrite(9, HIGH);
        }
        // si llega una L lo apagamos
        if (byteEntrante == 'L')
        {
            digitalWrite(9, LOW);
        }
    }
}
