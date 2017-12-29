import RPi.GPIO as GPIO
from ubidots import ApiClient
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(22, GPIO.IN)
GPIO.setup(17, GPIO.OUT)

api = ApiClient(token='SU-TOKEN')
contador = api.get_variable('ID-VARIABLE-CONTADOR')

def program():
        print "Ejecucion iniciada..."
        i = 0
        while 1:
                if GPIO.input(22):

                        while GPIO.input(22):
                                pass
                        i=i+1
                        print i
                        contador.save_value({"value": i})
        GPIO.cleanup()

program() ## Hago la llamada a la funcion
