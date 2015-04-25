n,s,t = map(int,raw_input().split())
w = int(raw_input())
cnt = 0
for i in range(n-1):
	a = int(raw_input())
	if s <= w and w <= t:
		cnt += 1
	w += a
if s <= w and w <= t:
	cnt += 1
print cnt
