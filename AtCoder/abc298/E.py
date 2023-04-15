''' E - Unfair Sugoroku '''
# https://atcoder.jp/contests/abc298/tasks/abc298_e
# Verdict: Not submitted

n, a, b, p, q = map(int, input().split())
m = 998244353

at = [0] * n
bt = [0] * n
for i in range(1, p + 1):
    for j in range(1, p + 1):
        at[i + j] += 1
for i in range(1, q + 1):
    for j in range(1, q + 1):
        bt[i + j] += 1
da = n - a
db = n - b

for t in range(min(da, db)):
    ...
