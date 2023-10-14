# Verdict: AC
def solve():
    k, d = map(int, (input() for _ in range(2)))

    sign = 1 if d & (1 << 63) == 0 else -1
    m = d & ((1 << k) - 1)
    p = (d & ((1 << 63) - 1 - ((1 << k) - 1))) >> k

    if p == ((1 << (63 - k)) - 1):
        print("NaN")
        return

    v = 0
    if p == 0:
        p = 1 - (1 << (62 - k)) - k
        v = m
    else:
        p = p + 1 - (1 << (62 - k)) - k
        v = (1 << k) + m

    while v & 1 == 0 and m != 0:
        v >>= 1
        p += 1
    v *= sign

    if v == 0:
        print(0)
        return

    if p == 0:
        print(v)
    if p > 0:
        print(f'{v}*2**{p}')
    if p < 0:
        print(f'{v}/2**{-p}')


solve()
