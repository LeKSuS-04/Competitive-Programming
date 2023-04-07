''' UVa 10312 - Expression Bracketing '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1253
# Date: 2021-09-19 06:13:29
# Runtime: 0.010
# Verdict: AC

from sys import stdin

cat = [-1, 1, 2]
scat = [-1, 1, 1]
MAX = 30
for i in range(MAX):
    n = len(cat) - 1
    cat += [cat[-1] * ((2*n + 1) * (2*n + 2)) // ((n + 1) * (n + 2))]

    n = len(scat)
    scat += [(3*(2*n - 3)*scat[-1] - (n - 3)*scat[-2]) // n]

for line in stdin:
    n = int(line.strip())
    if n in [1, 2]:
        print(0)
    else:
        print(scat[n] - cat[n - 1])