# Verdict: AC

_ = input()
arr = map(int, input().split())
mx = 10**12

for a in arr:
    if a > 0 and a % 2 == 0:
        mx = min(a, mx)
print(-1 if mx == 10**12 else mx)