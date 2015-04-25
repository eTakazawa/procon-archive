n = int(raw_input())
exist = [False] * 100001
cnt = 0
for i in range(n):
	a = int(raw_input())
	if exist[a]:
		cnt += 1
	exist[a] = True
print cnt