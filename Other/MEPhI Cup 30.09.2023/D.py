# Verdict: AC
from itertools import permutations

s = sorted(input().replace(' ', ''))
n = len(s)

k = set()

for i in range(1, n + 1):
    for p in permutations(s, r=i):
        k.add(''.join(p))

print(*k, sep='\n')