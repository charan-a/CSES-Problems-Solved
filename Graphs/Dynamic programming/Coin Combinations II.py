n,tar = map(int,input().split())
mod = 10**9 + 7
dp = [0]*(tar+1)
arr = list(map(int,input().split()))
arr.sort()
dp[0] = 1
for i in range(n):
    for j in range(1,tar+1):
        if arr[i] > j: continue
        dp[j] = (dp[j] + dp[j-arr[i]])%mod
 
print(dp[tar])