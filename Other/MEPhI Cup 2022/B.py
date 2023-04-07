a, b, c, d, e = map(int, input().split())

for x in range(-1000, 1001):
    if a * (x**4) + b * (x**3) + c * (x**2) + d * x + e == 0:
        print(x, end=' ')

print()