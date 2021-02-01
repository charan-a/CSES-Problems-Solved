n = int(input())
tot = n*(n+1)//2
val = tot//2
if tot&1:
    print("NO")
else:
    print("YES")
    ar1 = []
    ar2 = []
    while n:
        if val - n >= 0:
            val -= n
            ar1.append(n)
        else:
            ar2.append(n)
        n -= 1
    l1,l2 = len(ar1),len(ar2) 
    print(l1)
    for i in ar1:
        print(i,end=" ")
    print()
    print(l2)
    for j in ar2:
        print(j,end=" ")