''' UVa 10334 - Ray Through Glasses '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1275
# Date: 2021-09-14 18:56:48
# Runtime: 0.030
# Verdict: AC

from sys import stdin

MAX = 1010

memo = [1, 2, 3]
while len(memo) < MAX:
    memo.append(memo[-2] + memo[-1])

for line in stdin:
    n = int(line.strip())
    print(memo[n])