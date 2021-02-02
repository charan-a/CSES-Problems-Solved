n = int(input())
mat = []
mod = 10**9 + 7
 
for i in range(n):
    mat.append(input().strip())
 
dp = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        if mat[i][j] == "*":
              continue
        elif i == 0 and j == 0:
            dp[i][j] = 1  
        elif i == 0:
            dp[i][j] = 1 if dp[i][j-1] else 0
        elif j == 0:
            dp[i][j] = 1 if dp[i-1][j] else 0
        else:
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod
 
 
print(dp[n-1][n-1])