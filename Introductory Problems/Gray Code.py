n = int(input())
x = 0
mx = 1<<n
 
for i in range(mx):
    val = i ^ (i>>1)
    txt = ""
    for j in range(n-1,-1,-1):
        if (1<<j) & val:
            txt += '1'
        else:
            txt += '0'
    print(txt)