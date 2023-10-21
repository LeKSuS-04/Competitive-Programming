# Verdict: AC
n = int(input())
ps = []
for _ in range(n):
    a, b = map(int, input().split())
    ps.append((a, b))

ms = 0
for start_time in range(24):
    s = 0
    for a, b in ps:
        if (b + start_time) % 24 < 9:
            s += a
    if s > ms:
        ms = s
print(ms)
