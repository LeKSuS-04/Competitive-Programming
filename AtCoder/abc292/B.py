''' B - Yellow and Red Card '''
# https://atcoder.jp/contests/abc292/tasks/abc292_b
# Date: 2023-03-04 15:03:36
# Run time: 22 ms
# Memory: 9060 KB
# Verdict: AC

n, q = map(int, input().split())
s = [0] * n
for i in range(q):
    e, p = map(int, input().split())
    if e == 3:
        print('Yes' if s[p - 1] >= 2 else 'No')
    else:
        s[p - 1] += e