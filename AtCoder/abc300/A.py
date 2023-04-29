''' A - N-choice question '''
# https://atcoder.jp/contests/abc300/tasks/abc300_a
# Date: 2023-04-29 15:01:09
# Run time: 24 ms
# Memory: 8972 KB
# Verdict: AC
n, a, b = map(int, input().split())
c = list(map(int, input().split()))
print(c.index(a + b) + 1)