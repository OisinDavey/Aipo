import sys
import math

n,k = map(int,input().split())

a = list(map(int,input().split()))

d = 0

b = 0

for i in a:
    d += 1
    k -= i
    if(k<0):
        print(d)
        b = 1
        break
        
if b == 0:
    print(d)
