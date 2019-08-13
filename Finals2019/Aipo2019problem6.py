import sys
import math
 
def f(x,y,o,d):
    if( ( (3**(d-1) <= x) and (x < (2*(3**(d-1) ) ) ) ) and ( ( (3**(d-1) ) <= y ) and (y < 2*(3**(d-1) ) ) ) ):
        return 'w'
    elif(o==1):
        return 'b'
    else:
        if(2*(3**(d-1) ) <= x):
            x-=2*(3**(d-1) )
        elif (3**(d-1) <= x):
            x-=3**(d-1)
        if(2*(3**(d-1) ) <= y):
            y-=2*(3**(d-1) )
        elif (3**(d-1) <= y):
            y-=3**(d-1)
        return f(x,y,o-1,d-1)
    
D,O,N = map(int,input().split())

for i in range(0,N):
    x,y = map(int,input().split())
    print(f(x,y,O,D),end = ' ')
