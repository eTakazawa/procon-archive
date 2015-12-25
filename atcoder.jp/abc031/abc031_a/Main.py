a = map(int,raw_input().split())
x = (a[0]+1)*a[1]
y = a[0]*(a[1]+1)
if x > y:
	print x
else:
	print y