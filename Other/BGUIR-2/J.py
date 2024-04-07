# Verdict: AC

n, k = map(int, input().split())
a = [int(x) for x in input().split()]
a[0] = 1

l = 1
r = 10**12


def satisfies(m: int) -> bool:
    for i, ai in enumerate(a):
        if m**i - ai > k:
            return False
    return True


while r - l > 1:
    m = (r + l) // 2
    if satisfies(m):
        l = m
    else:
        r = m

print(l)
