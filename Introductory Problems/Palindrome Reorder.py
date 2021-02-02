from collections import defaultdict
str = input().strip()
ddic = defaultdict(int)
for c in str:
    ddic[c] += 1
fr = ""
mid =""
cnt = 0
for x,y in ddic.items():
    if y & 1:
        mid = x*y ;cnt += 1
        if cnt > 1: break
    else:
        y //= 2
        fr += x*y
    
    
 
if cnt > 1:
    print("NO SOLUTION")
else:
    s = fr + mid + fr[::-1]
    print(s)