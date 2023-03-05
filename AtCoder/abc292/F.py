''' F - Regular Triangle Inside a Rectangle '''
# https://atcoder.jp/contests/abc292/tasks/abc292_f
# Date: 2023-03-04 15:58:03
# Run time: 27 ms
# Memory: 9372 KB
# Verdict: AC

from math import *

n, m = map(int, input().split())
if n < m:
    n, m = m, n


def to_rad(deg: float) -> float:
    return deg * pi / 180


def can_fit(side: float) -> bool:
    if side <= n:
        return True
    
    a_cos = m / side
    a_sin = sqrt(1 - a_cos**2)
    x1 = a_sin * side
    y1 = m

    b_cos = n / side
    b_sin = sqrt(1 - b_cos**2)
    x2 = n
    y2 = b_sin * side

    return sqrt((y1 - y2)**2 + (x1 - x2)**2) >= side



# n is max
e = 1e-11
l = m
r = m / cos(to_rad(30))
while r - l > e:
    t = (r + l) / 2
    if can_fit(t):
        l = t
    else:
        r = t
print(l)
