import serial
import csv

ser = serial.Serial( port = '/dev/cu.usbmodem14201' )
ser.flushInput()

while True:

    try:
        line = ser.readline()
        line = line.decode( "utf-8" ) 
        print(line)
        with open( "H11F3.csv", "a", newline="" ) as f:
            writer = csv.writer(f)
            writer.writerow(line)

    except KeyboardInterrupt:
        break