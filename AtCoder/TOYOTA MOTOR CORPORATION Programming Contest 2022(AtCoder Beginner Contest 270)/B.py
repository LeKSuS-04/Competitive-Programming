''' B - Hammer '''
# https://atcoder.jp/contests/abc270/tasks/abc270_b
# Date: 2022-09-24 15:06:25
# Runtime: 94 ms
# Memory: 61748 KB
# Verdict: AC

x, y, z = map(int, input().split())

if abs(x) < abs(y) or x * y < 0:
    print(abs(x))
    exit()

if abs(z) > abs(y) and z * y > 0:
    print(-1)
    exit()
    
if z * y > 0:
    print(abs(x))
else:
    print(abs(x) + 2*abs(z))
