g = [
  [1,3,5,7,8,10,12],
  [4,6,9,11],
  [2]
  ]

def get_group(n):
  for i, gg in enumerate(g):
    if n in gg:
      return i


x, y = list(map(int, input().split()))

if get_group(x) == get_group(y):
  print('Yes')
else:
  print('No')
