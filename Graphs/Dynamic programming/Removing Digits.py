from  math import inf
n = int(input())
dp = [inf]*(max(11,n+1))
dp[0] = 0
for i in range(1,10):
    dp[i] = 1
 
for i in range(10,n+1):
    s = str(i)
    for j in range(len(s)):
        val = i - int(s[j])
        dp[i] = min(dp[val]+1,dp[i])
 
 
print(dp[n])