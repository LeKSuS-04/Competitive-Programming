# Verdict: AC
n, s = input().split()
n = int(n)


def kek(a, b):
    if len(a) == len(b):
        return sum(a[i] != b[i] for i in range(len(a))) < 2
    elif len(a) + 1 == len(b):
        i = 0
        while i < len(a) and a[i] == b[i]:
            i += 1
        while i < len(a) and a[i] == b[i + 1]:
            i += 1
        return i == len(a)
    elif len(a) == len(b) + 1:
        i = 0
        while i < len(b) and a[i] == b[i]:
            i += 1
        while i < len(b) and a[i + 1] == b[i]:
            i += 1
        return i == len(b)

    return False


good = []
for i in range(n):
    t = input()
    if kek(s, t):
        good.append(i + 1)

print(len(good))
print(*good)
