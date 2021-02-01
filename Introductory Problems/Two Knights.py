n = int(input())
var = 1
for i in range(1,n+1):
    j = i*i
    tot = j*(j-1)//2
    var += i-2
    res = tot - 8*(var)
    print(res)