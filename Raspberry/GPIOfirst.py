import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT) ## GPIO 17 como salida
GPIO.setup(27, GPIO.OUT) ## GPIO 27 como salida

def blink():
        print "Comienzo Programa..."
        while 1:
                GPIO.output(17, True) 	## Enciendo el 17
                GPIO.output(27, False) 	## Apago el 27
                time.sleep(1) 			## Esperamos 1 segundo
                GPIO.output(17, False) 	## Apago el 17
                GPIO.output(27, True) 	## Enciendo el 27
                time.sleep(1) 			## Esperamos 1 segundo
        GPIO.cleanup() ## Hago una limpieza de los GPIO	
        
blink()	##llamamos a la funcion
