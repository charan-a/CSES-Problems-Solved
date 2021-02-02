n,tar = map(int,input().split())
mod = 10**9 + 7
dp = [0]*(tar+1)
arr = list(map(int,input().split()))
arr.sort()
dp[0] = 1
for j in range(tar+1):
    for i in range(n):
        if arr[i] > j: break
        dp[j] = (dp[j] + dp[j-arr[i]])%mod
 
print(dp[tar])