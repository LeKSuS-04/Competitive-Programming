''' A. A Recursive Function '''
# https://atcoder.jp/contests/abc273/tasks/abc273_a
# Date: 2022-10-15 15:00:53
# Run time: 25 ms
# Memory: 9096 KB
# Verdict: AC

def fact(n):
    if n < 2:
        return 1
    else:
        return n * fact(n - 1)

print(fact(int(input())))