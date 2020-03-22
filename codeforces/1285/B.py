def solve(n) :
    li = list(map(int,input().split()))
    pref = 0
    for i in range(0,len(li)-1) : 
        pref += li[i]
        if pref <= 0 : 
            print("NO")
            return
    suf = 0
    for i in range(len(li)-1,-1,-1) : 
        suf += li[i] 
        if suf <= 0 :
            print("NO")
            return 
    print("YES")
    return

t = int(input())

for _ in range(t) : 
    n = int(input())
    solve(n)
