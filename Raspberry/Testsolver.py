import sympy
import time
#from sympy.solvers import solve
from sympy import *



B11 = 2.32
B12 = 2.55
B13 = 3.11
B21 = 1.44
B22 = 3.2
B23 = 0.55
B31 = 0.2
B32 = 1.78
B33 = 1.93
Bt = 10.004

x = Symbol ('x')
y = Symbol ('y')
z = Symbol ('z')

R =sqrt(x**2 + y**2 + z**2)
lastx = 1
lasty = 1
lastz = 1
for i in range(1,10) :
    ms = time.time()*1000.0
    [lastx, lasty, lastz] = nsolve([3*Bt*x*y/R**6-B12, 3*Bt*x*z/R**6-B13, 3*Bt*z*y/R**6-B23], [x,y,z],[lastx-0.1,lasty-0.1,lastz-0.1])
    print(time.time()*1000.0-ms)
    print("x = {0} y = {1} z = {2}".format(lastx,lasty,lastz))
    B12+= 0.1
    B13+= 0.1
    B23+= 0.1
    
