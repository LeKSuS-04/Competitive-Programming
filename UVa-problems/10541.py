''' UVa 10541 - Stripe '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1482
# Date: 2021-09-16 17:21:26
# Run time: 0.000
# Verdict: AC

from sys import stdin

def fact(n):
    ans = 1
    for i in range(2, n + 1):
        ans *= i
    return ans

def C(k, n):
    if n == 0 or k == 0:
        return 1
    else:
        return fact(n) // fact(k) // fact(n - k)

if __name__ == '__main__':
    for line in stdin:
        test = list(map(int, line.strip().split()))

        if (len(test) == 1):
            continue

        n, k, code = test[0], test[1], test[2:]

        holes = k - 1
        edges = 2
        to_be_filled = n - sum(code) - holes

        print(C(to_be_filled, to_be_filled + holes + edges - 1))