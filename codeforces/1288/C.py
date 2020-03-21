N = 1100
dp = [[-1 for c in range(N)] for r in range(N) ]
MOD = 10**9 + 7

def ncr(n,r):
    if n < r : 
        return 0
    if n == r or r == 0 : 
        return 1
        
    if dp[n][r] != -1 :
        return dp[n][r]
    
    dp[n][r] = ncr(n-1,r) + ncr(n-1,r-1) 
    if dp[n][r] >= MOD :
        dp[n][r] -= MOD
    return dp[n][r]

def solve(n,m) :
    print(ncr(n=n+2*m-1,r=2*m))

while True :
    try: 
        n,d = map(int,input().split())
        solve(n,d) 

    except EOFError:
        break
