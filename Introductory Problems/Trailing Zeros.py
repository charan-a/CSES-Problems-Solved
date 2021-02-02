n = int(input())
cnt = 0
x = 5
while n//x > 0:
    cnt += n//x
    x *= 5
print(cnt)