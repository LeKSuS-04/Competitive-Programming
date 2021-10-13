''' UVa 11879 - Multiple of 17s '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3001
# Date: 2021-08-14 17:43:55
# Run time: 0.010
# Verdict: AC

from sys import stdin


for line in stdin:
    if line == '0\n':
        break

    a = int(line.strip())
    print(1 if a % 17 == 0 else 0)