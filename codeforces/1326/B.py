import sys
input = sys.stdin.readline

n = int(input())
x = [] 
mx = 0
v = list(map(int,input().split()))

for el in v : 
    x.append(el + mx)
    mx = max(mx,el + mx)
print(*x)


        

