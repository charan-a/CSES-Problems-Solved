n = int(input())
arr = list(map(int,input().split()))
mx = 0
var = 0
tot = sum(arr)
val = tot//2
for i in range(1,1<<n+1):
    var = 0
    for j in range(n):
        if i>>j & 1:
            var += arr[j]
    if var <= val:
        mx = max(var,mx)

print(tot-2*mx)