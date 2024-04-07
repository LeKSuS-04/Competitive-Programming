n = int(input())
for a in range(n + 1):
    for b in range(n + 1):
        for c in range(n + 1):
            if a + b + c <= n:
                print(a, b, c)
