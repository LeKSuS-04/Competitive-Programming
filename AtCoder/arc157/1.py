''' A - XXYYX '''
# https://atcoder.jp/contests/arc157/tasks/arc157_a
# Date: 2023-02-25 15:09:56
# Run time: 23 ms
# Memory: 9120 KB
# Verdict: AC

n, a, b, c, d = map(int, input().split())
x_starts = a + b
x_ends = a + c
y_starts = c + d
y_ends = b + d

x_d = abs(x_starts - x_ends)
y_d = abs(y_starts - y_ends)

if x_d + y_d <= 2 and (b + c > 0 or d == 0 or a == 0):
    print('Yes')
else:
    print('No')
