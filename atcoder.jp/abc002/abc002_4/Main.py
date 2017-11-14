N,M = map(int, raw_input().split())
kankei = []
for i in range(M):
  x,y = map(int, raw_input().split())
  x -= 1
  y -= 1
  kankei.append((x,y))
  kankei.append((y,x))
ret = 0
for i in range(1<<N):
  ok = True
  for j in range(N):
    for k in range(N):
      if j == k: continue
      if ((i >> j) & 1) and ((i >> k) & 1):
        if not (j,k) in kankei: ok = False
  if ok: ret = max(bin(i).count("1"), ret)
print ret