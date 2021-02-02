mod = 10**9+7
n = int(input())
dp = [0 for i in range(n+1)]
dp[0] = 1
for i in range(1,n+1):
    for j in range(1,7):
        if i - j >= 0:
            dp[i] += dp[i-j]
            dp[i] %= mod
print(dp[n])
