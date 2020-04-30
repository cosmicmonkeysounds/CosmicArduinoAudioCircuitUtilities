import matplotlib.pyplot as plt
import csv

x = [ x for x in range(1200, 2601) ] # Pretty much seems to the useful range of an OptoFET hooked up to a 12-bit DAC
y = []

with open("H11F3.csv", 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',') 
    for row in plots:
        cleanRow = [ float(e.replace(" ", "").replace("\n", "")) for e in row ]
        print(cleanRow)
        y.append(cleanRow)

plt.figure(1) # Each R1 value on their own line

for r in y:
    plt.plot(x,r, label=r[0])

plt.xlabel('DAC Value')
plt.ylabel('Resistance from OptoCoupler (ohms)')
plt.title('H11F3 FET\nResistance vs. 12-Bit DAC Value vs. R1')
plt.axis( [1500, 1900, -100000, 4000000] )
plt.legend()

plt.figure(2) # The average value of every R1 on one line

avg = [0] * len(y[0])
for i in range( len(y[0]) ):
    for j in range( len(y) ):
        avg[i] = y[j][i]
avg = [ e // len(y) for e in avg ]

plt.plot(x, avg)
plt.xlabel('DAC Value')
plt.ylabel('Resistance from OptoCoupler (ohms)')
plt.title('H11F3 FET\nAverage Resistance vs. 12-Bit DAC Value')
plt.axis( [1500, 1800, -100000, 1000000] )
plt.show()
