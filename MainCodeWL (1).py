import urllib.request
import serial, time

def SerialCommRead():
    global ser
    if ser.in_waiting>0:
        Val=ser.readline().decode("ascii").rstrip()
        return Val

ser=serial.Serial('/dev/ttyACM0',9600)
ser.flush()

while True:
    print("Receiving")
    Val=SerialCommRead()
    if str(Val)!='None':
        LocL=Val.find("L")
        LocP=Val.find("P")
        Link='https://api.thingspeak.com/update?api_key=OORPBGK7HTDS6IHA&field1='+str(Val[2:LocP])+'&field2='+str(Val[LocP+1:])
        Rspn=urllib.request.urlopen(Link)
    time.sleep(1)
    ser.flush()
