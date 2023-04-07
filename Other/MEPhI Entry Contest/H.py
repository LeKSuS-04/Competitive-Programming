''' H. Массив '''
# Date: 1 Sep 2022, 11:32:50 (+01:32)
# Run time: 333ms
# Memory: 43.18Mb
# Verdict: AC

n = int(input())
a = list(map(int, input().split()))

a = sorted(a)

print(sum(abs(ai - a[n//2]) for ai in a))
