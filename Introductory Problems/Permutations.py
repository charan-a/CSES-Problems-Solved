from math import ceil
n = int(input())
if n == 1:
    print(1)
elif n < 4:
    print("NO SOLUTION")
elif n == 4 :
    print("3 1 4 2")
else:
    if n&1:
        mid = ceil(n / 2)
        i = 1; j = mid+1
        print(mid,end=" ")
        for x in range(mid-1):
            print(i,j,sep=" ",end=" ")
            i += 1; j += 1
    else:
        mid1 = n//2; mid2 = mid1+1
        i = 1; j = mid2+1
        print(mid1,end=" ")
        for x in range(mid1-1):
            print(i,j,sep=" ",end=" ")
            i += 1; j += 1
        print(mid2,end=" ")