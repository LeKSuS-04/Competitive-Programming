''' 1809B. Points on Plane '''
# https://codeforces.com/contest/1809/problem/B
# Date: Mar/23/2023 18:03
# Run time: 218 ms
# Memory: 7120 KB
# Verdict: AC

from math import *
TC = int(input())
for _ in range(TC):
    t = int(input())
    if t == 0:
        print(0)
    else:
        a = isqrt(t - 1)
        print(a)
