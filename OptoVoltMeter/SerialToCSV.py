import serial
import csv

ser = serial.Serial( port = '/dev/cu.usbmodem14201' )
ser.flushInput()
resValues = []

while True:

    try:
        line = ser.readline().decode( "utf-8" ).split(":")
        print(line)

        if line[0] == "Resistance" or line[0] == "Resistor":
            resValues.append(line[1])
            if len(resValues) < 1401: 
                continue

        with open( "H11F3.csv", "a", newline="" ) as f:
            writer = csv.writer(f, delimiter = ",")
            writer.writerow(resValues)
            resValues = []

    except KeyboardInterrupt:
        break