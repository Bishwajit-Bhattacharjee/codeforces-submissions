import io
import os
import sys
from io import BytesIO
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t) :
    n,k = map(int,input().split())
    ans = n - (k-1)*(k-1)
    print(["YES","NO"][not(ans & 1 and ans > (2*k-3))])
