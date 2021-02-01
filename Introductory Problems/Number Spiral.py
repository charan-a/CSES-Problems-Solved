for _ in range(int(input())):
    y,x = map(int,input().split())
    if x > y:
        if x&1:
            val = x*x - y + 1
        else:
            x -= 1
            val = x*x + y
    else:
        if not y&1:
            val = y*y - x + 1
        else:
            y -= 1
            val = y*y + x
    print(val)