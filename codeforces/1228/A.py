
def diff(n):
    dict = {}
    while(n) : 
        if (n % 10) in dict :
            return False
        dict[n%10] = 1
        n //= 10
    return True

#print(diff(98766))
l,r = map(int,input().split())
for _ in range(l,r+1):
    if diff(_) :
        print(_)
        exit(0)
print("-1")