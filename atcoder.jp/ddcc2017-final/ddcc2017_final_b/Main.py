def gcd(a,b):
  if b==0: return a;
  return gcd(b,a%b);

def lcm(a, b):
  return a * b / gcd(a, b);

n,z = map(int,raw_input().split())

a = map(int,raw_input().split())
ret = 1
for ai in a:
  ret = lcm(ret, gcd(ai, z))
print ret
