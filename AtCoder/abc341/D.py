from math import lcm

n, m, k = map(int, input().split())
n_m_lcm = lcm(n, m)

l = 0
r = 1 << 64


def more_before(t: int) -> bool:
    n_div = t // n
    m_div = t // m
    both_div = t // n_m_lcm
    return (n_div + m_div - 2 * both_div) > k


while l < r - 1:
    t = l + (r - l) // 2
    if more_before(t):
        r = t
    else:
        l = t

r_m = l - l % m
r_n = l - l % n
print(max(r_m, r_n))
