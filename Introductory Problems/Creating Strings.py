from collections import deque
sg = input().strip()
lis =list(sg)
n = len(lis)
lis.sort()
dq = deque()
dq.append([])
res = []
for c in lis:
    l = len(dq)
    for i in range(l):
        it = dq.popleft()
        for j in range(len(it)+1):
            new = list(it)
            new.insert(j,c)
            if len(new) == n:
                res.append(new)
            else:
                dq.append(new)
st = set()
ans = []
r = len(res)
for i in range(r-1,-1,-1):
    it = res[i]
    sg = "".join(it)
    if sg not in st:
        st.add(sg)
        ans.append(sg)
print(len(ans))
ans.sort()
for sg in ans:
    print(sg)
