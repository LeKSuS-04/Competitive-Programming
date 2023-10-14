# Verdict: AC
input()
a = list(map(int, input().split()))

if all(ai == a[0] for ai in a):
    print('Yes')
else:
    print('No')
