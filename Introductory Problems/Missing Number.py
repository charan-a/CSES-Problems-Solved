n = int(input())
arr = list(map(int,input().split()))
xor = n
for i in range(n-1):
    xor = xor ^ arr[i] ^ (i+1)
print(xor)