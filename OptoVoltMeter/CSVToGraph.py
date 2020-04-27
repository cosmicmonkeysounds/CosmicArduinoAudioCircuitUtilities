import numpy as np
from numpy.polynomial.polynomial import polyfit
import matplotlib.pyplot as plt
import csv

x = [ x for x in range(1200, 2601) ]
y = []

with open( "H11F3.csv", 'r' ) as csvfile:
    plots = csv.reader( csvfile, delimiter=',') 
    for row in plots:
        cleanRow = [ float( e.replace(" ", "").replace("\n", "") ) for e in row ]
        print( cleanRow )
        y.append( cleanRow )

plt.figure(1)
for r in y:
    plt.plot(x,r, label=r[0])
plt.xlabel('DAC Value')
plt.ylabel('Resistance from OptoCoupler (ohms)')
plt.title('H11F3 FET\nResistance vs. 12-Bit DAC Value vs. R1')
plt.axis( [1500, 1900, -230000, 4000000] )
plt.legend()

plt.figure(2)
lin1 = np.array( y[0] )
lin2 = np.array( y[1] )
b, m = polyfit(lin1, lin2, 1)
plt.plot(lin1, lin2, '.')
plt.plot(lin1, b+m*lin1, '-')

plt.show()

input()