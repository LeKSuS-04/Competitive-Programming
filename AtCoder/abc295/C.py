''' C - Socks '''
# https://atcoder.jp/contests/abc295/tasks/abc295_c
# Date: 2023-03-25 15:10:46
# Run time: 382 ms
# Memory: 93916 KB
# Verdict: AC

from collections import defaultdict
_ = input()
a = map(int, input().split())
d = defaultdict(lambda: 0)
for i in a:
    d[i] += 1
answ = 0
for v in d.values():
    answ += v // 2
print(answ)