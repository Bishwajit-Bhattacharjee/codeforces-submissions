import math
def gcd(a,b) : 
    if b == 0 : 
        return a
    return gcd(b,a%b)

def lcm(a,b) : 
    return a*b/gcd(a,b)
    
def solve(n) :
    mx = 10**13
    for a in range(1,int(math.sqrt(n))+10) :
        if n % a == 0 :
            if max(a,n//a) < mx and lcm(a,n//a) == n : 
                mx = max(a,n//a)
                A = a
                B = n // a
    print("{} {}".format(A,B))

while True :
    try :
        n = int(input())
        solve(n)
    except EOFError :
        break
