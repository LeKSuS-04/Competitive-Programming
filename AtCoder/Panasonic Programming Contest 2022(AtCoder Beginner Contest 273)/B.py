''' B. Broken Rounding '''
# https://atcoder.jp/contests/abc273/tasks/abc273_b
# Date: 2022-10-15 15:06:54
# Run time: 25 ms
# Memory: 9200 KB
# Verdict: AC

x, k = map(int, input().split())

def bround(n, p):
    t = 10**p
    a = n // t * t
    b = (n // t + 1) * t
    if abs(n - a) < abs(n - b):
        return a
    return b

for i in range(1, k + 1):
    x = bround(x, i)

print(x)