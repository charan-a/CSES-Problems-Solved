for _ in range(int(input())):
    a,b = map(int,input().split())
    x = (2*a-b)/3; y = (2*b-a)/3
    if int(x) == x and int(y) == y and x > -1 and y > -1:
        print("YES")
    else:
        print("NO")