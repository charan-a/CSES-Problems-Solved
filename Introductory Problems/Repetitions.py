    str = input().strip()
mx = 1 ; temp = 1
l = len(str)
for i in range(1,l):
    if str[i] == str[i-1]:
        temp += 1
        mx = max(mx,temp)
    else:
        temp = 1
print(mx)