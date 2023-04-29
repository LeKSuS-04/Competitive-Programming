''' E - Dice Product 3 '''
# https://atcoder.jp/contests/abc300/tasks/abc300_e
# Date: 2023-04-29 15:59:25
# Run time: 109 ms
# Memory: 10788 KB
# Verdict: AC

from fractions import Fraction

MOD = 998244353

memo = {1: Fraction(1)}
def get_prob(n: int) -> Fraction:
    if n in memo.keys():
        return memo[n]
    prob = Fraction(0)
    for i in range(2, 6 + 1):
        if n % i == 0:
            prob += Fraction(1, 5) * get_prob(n // i)
    memo[n] = prob
    return memo[n]


n = int(input())
f = get_prob(n)
print(f.numerator * pow(f.denominator, -1, MOD) % MOD)
