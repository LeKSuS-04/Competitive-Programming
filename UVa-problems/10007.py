''' UVa 10007 - Count the Trees '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=948
# Date: 2021-09-19 05:38:08
# Runtime: 0.010
# Verdict: AC

from sys import stdin

cat = [1, 1, 2]
fact = [1, 1]
MAX = 310
for n in range(2, MAX):
    Cn = cat[-1]
    cat += [Cn * ((2*n + 1) * (2*n + 2)) // ((n + 1) * (n + 2))]
    fact += [fact[-1] * n]

for line in stdin:
    n = int(line.strip())
    if n != 0:
        print(fact[n] * cat[n])