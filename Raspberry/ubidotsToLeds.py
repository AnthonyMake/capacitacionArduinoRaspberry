import RPi.GPIO as GPIO
from ubidots import ApiClient
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)

api = ApiClient(token='SU-TOKEN')
led2 = api.get_variable('VAR-ID-LED2')
led1 = api.get_variable('VAR-ID-LED1')

def program():
        print "Ejecucion iniciada..."

        while 1:
                valorLed1 = led1.get_values(1)
                valorLed2 = led2.get_values(1)

                print "led 1 " + str(valorLed1[0]['value'])+", led 2 "+ str(valorLed2[0]['value'])

                if valorLed1[0]['value']==1.0:
                        GPIO.output(17,True)
                else:
                        GPIO.output(17,False)

                if valorLed2[0]['value']==1.0:
                        GPIO.output(27,True)
                else:
                        GPIO.output(17,False)

                if valorLed2[0]['value']==1.0:
                        GPIO.output(27,True)
                else:
                        GPIO.output(27,False)
        GPIO.cleanup()

program() ## Hago la llamada a la funcion
