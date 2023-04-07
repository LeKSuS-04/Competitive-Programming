''' B. Наибольший общий делитель '''
# Date: 1 Sep 2022, 10:03:36 (+00:03)
# Run time: 99ms
# Memory: 4.24Mb
# Verdict: AC

from math import gcd
a, b = map(int, input().split())
print(gcd(a, b))