''' UVa 465 - Overflow '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=406
# Date: 2021-08-14 17:38:54
# Run time: 0.010
# Verdict: AC

from sys import stdin

limit = 2 ** 31 - 1

for line in stdin:
    a, action, b = line.strip().split()
    print(a, action, b)

    a, b = int(a), int(b)


    if a > limit:
        print('first number too big')
    if b > limit:
        print('second number too big')

    if action == '*' and a == 0 or b == 0:
        continue

    if (a > limit or b > limit):
        print('result too big')
    else:
        res = a + b if action == '+' else a * b
        if res > limit:
            print('result too big')
