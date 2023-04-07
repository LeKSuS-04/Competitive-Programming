''' A - Наивный RMQ '''
# Date: 2022-12-08 21:06:18
# Run time: 218 ms
# Memory: 3708 KB
# Verdict: AC

import sys

with open('stupid_rmq.in', 'r') as fin, open('stupid_rmq.out', 'w') as fout:
    sys.stdin = fin
    sys.stdout = fout

    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())

    for _ in range(m):
        l, r = map(int, input().split())
        print(min(a[l - 1 : r]))
