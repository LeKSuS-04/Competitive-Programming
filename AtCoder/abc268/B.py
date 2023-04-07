''' B - Prefix? '''
# https://atcoder.jp/contests/abc268/tasks/abc268_b
# Date: 2022-09-10 15:02:02
# Runtime: 26 ms
# Memory: 9052 KB
# Verdict: AC

s = input()
t = input()

print('Yes' if t.startswith(s) else 'No')