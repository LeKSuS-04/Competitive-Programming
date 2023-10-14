# Verdict: AC
def solve():
    k = int(input())
    a = list(map(int, (input() for _ in range(k))))

    for i in range(k):
        s = 0
        for j in range(i, k):
            s += a[j]
            if j - i >= 2 and s < 180 * (j - i - 2 + 1):
                print(-1)
                return

    s = sum(a)
    mx = k
    while s != 180 * (mx - 2):
        s += 179
        mx += 1

    mn = 0
    if k == 1:
        mn = 3
    else:
        if k > 2 and 180 * (k - 2) == sum(a):
            mn = k
        elif 0 < 180 * (k - 1) - sum(a) < 180:
            mn = k + 1
        else:
            mn = k + 2

    print(mn, mx)


solve()
