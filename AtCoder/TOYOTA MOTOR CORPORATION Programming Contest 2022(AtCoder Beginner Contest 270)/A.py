''' A - 1-2-4 Test '''
# https://atcoder.jp/contests/abc270/tasks/abc270_a
# Date: 2022-09-24 15:02:02
# Runtime: 67 ms
# Memory: 61528 KB
# Verdict: AC

a, b = map(int, input().split())

x = (a & 1) | (b & 1)
y = (a & 2) | (b & 2)
z = (a & 4) | (b & 4)

print(x + y + z)