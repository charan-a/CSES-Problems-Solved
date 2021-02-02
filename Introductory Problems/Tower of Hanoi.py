def rec(n,frm,spr,to):
    if n == 1:
        print(frm,to)
    else:
        rec(n-1,frm,to,spr)
        rec(1,frm,spr,to)
        rec(n-1,spr,frm,to)
 
 
n = int(input())
print((1<<n)-1)
rec(n,1,2,3)