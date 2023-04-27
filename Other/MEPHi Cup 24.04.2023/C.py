# Verdict: AC

from math import gcd

_ = input()
arr = list(map(int, input().split()))

g = 0
for i, a in enumerate(arr):
    for j, b in enumerate(arr):
        if i != j:
            g = max(gcd(a, b), g)
print(g)