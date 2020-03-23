
def solve():
    n = int(input())
    s = str(input())
    ans = 0
    cnt = 0
    found = False
    for id in range(n) :
        if s[id] == 'P' : cnt += 1
        else :
            if found : ans = max(ans,cnt)
            found = True
            cnt = 0
    if found : ans = max(ans,cnt)
    print(ans)


t = int(input())
for _ in range(t): 
    solve()
