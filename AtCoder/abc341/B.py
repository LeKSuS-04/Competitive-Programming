n = int(input())
a = [int(x) for x in input().split()]
for i in range(n - 1):
    x, y = map(int, input().split())
    a[i + 1] += y * (a[i] // x)
print(a[-1])
